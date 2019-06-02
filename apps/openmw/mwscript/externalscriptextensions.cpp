
#include "bindings/bindingsvars.hpp"

#include <components/compiler/extensions.hpp>
#include <components/compiler/opcodes.hpp>

#include <components/interpreter/interpreter.hpp>
#include <components/interpreter/runtime.hpp>
#include <components/interpreter/opcodes.hpp>
#include <components/interpreter/context.hpp>
#include <components/files/configurationmanager.hpp>

#include "interpretercontext.hpp"
#include "extensions.hpp"
#include "bindings/extensionsbindings.hpp"
#include "ref.hpp"

#include <iostream>

namespace MWScript
{
    namespace ExternalScript
    {
        class OpStartExternalScript : public Interpreter::Opcode0
        {
            public:
                virtual Files::PathContainer getextensionsdir()
                {
                    boost::program_options::variables_map variables;
                    boost::program_options::options_description desc("Allowed options");
                    desc.add_options()
                    ("data", boost::program_options::value<Files::PathContainer>()->default_value(Files::PathContainer(), "data")->multitoken()->composing())
                    ("data-local", boost::program_options::value<std::string>()->default_value(""))
                    ("extensions", boost::program_options::value<Files::PathContainer>()->default_value(Files::PathContainer(),""));

                    boost::program_options::notify(variables);

                    Files::ConfigurationManager cfgManager;
                    cfgManager.readConfiguration(variables, desc);

                    Files::PathContainer dataDirs, dataLocal;
                    if (!variables["data"].empty()) {
                        dataDirs = Files::PathContainer(variables["data"].as<Files::PathContainer>());
                    }

                    std::string local = variables["data-local"].as<std::string>();
                    if (!local.empty()) {
                        dataLocal.push_back(Files::PathContainer::value_type(local));
                    }

                    cfgManager.processPaths (dataDirs);
                    cfgManager.processPaths (dataLocal, true);

                    if (!dataLocal.empty())
                        dataDirs.insert (dataDirs.end(), dataLocal.begin(), dataLocal.end());

                    Files::PathContainer extensionDirs = variables["extensions"].as<Files::PathContainer>();
                    extensionDirs.insert(extensionDirs.end(),dataDirs.begin(), dataDirs.end());
                    return extensionDirs;
                }

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    std::string scriptname = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    if (scriptname.find(".lua") != std::string::npos)
                    {
                        MWScript::InterpreterContext luaContext = static_cast<InterpreterContext&> (runtime.getContext());
                        MWScriptExtensions::context = &luaContext;
                        if(!MWScriptExtensions::luaState)
                        {
                            MWScriptExtensions::luaState = luaL_newstate();
                            luaL_openlibs(MWScriptExtensions::luaState);
                            Files::PathContainer extensionDirs = getextensionsdir();

                            for (unsigned i=extensionDirs.size(); i-- > 0;)//reverse order
                            {
                                std::string pathAppend("package.cpath=package.cpath..\";" + extensionDirs.at(i).string() +  "/?.so;"+ extensionDirs.at(i).string()+"/?.dll\"");
                                luaL_dostring(MWScriptExtensions::luaState, pathAppend.c_str());
                                pathAppend = "package.path=package.path..\";" + extensionDirs.at(i).string() +  "/?.lua\"";
                                luaL_dostring(MWScriptExtensions::luaState, pathAppend.c_str());
                                std::cout << pathAppend << "\n";
                            }
                            luaL_dostring(MWScriptExtensions::luaState, "omw = require(\"liblua_openmw\")");
                            //lua scripts are modules with run() function
                        }
                        std::string luaModuleName = scriptname.substr(0, scriptname.size()-4);
                        std::string executeString(luaModuleName + " = require(\""+ luaModuleName + "\")");

                        if(luaL_dostring(MWScriptExtensions::luaState, executeString.c_str() ))
                        {
                            std::cerr << "can't find lua module: "<< luaModuleName << "\n";
                            return;
                        }

                        executeString = luaModuleName + ".run()";

                        int rv = luaL_dostring(MWScriptExtensions::luaState, executeString.c_str());
                        if(rv)
                        {
                            std::cerr << "error when executing module \""<< luaModuleName << "\": " << lua_tostring(MWScriptExtensions::luaState,-1) << std::endl;
                            return;
                        }
                    }
                    else
                    {
                        std::cerr << "StartExternalScript: " << scriptname << " is not valid external script name";
                    }
                }
        };
        class OpExternalScriptReturn : public Interpreter::Opcode0
        {
            public:

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScriptExtensions::stackReturn = runtime[0];
                }
        };


        void installOpcodes (Interpreter::Interpreter& interpreter)
        {
            interpreter.installSegment5 (Compiler::ExternalScript::opcodeStartExternalScript, new OpStartExternalScript);
            interpreter.installSegment5 (Compiler::ExternalScript::opcodeExternalScriptReturn, new OpExternalScriptReturn);
        }
    }
}

