//THIS FILE IS CREATED BY EXTENSIONSTOOL, DO NOT EDIT

#include "extensionsbindings.hpp"
#include "bindingsvars.hpp"

#include <sys/types.h>                  // for uint
#include <algorithm>                    // for copy
#include <iterator>                     // for back_inserter, etc
#include <vector>                       // for vector, etc

#include <components/compiler/generator.hpp>  // for pushString, pushInt, etc
#include <components/compiler/literals.hpp>  // for Literals
#include <components/compiler/opcodes.hpp>
#include <components/interpreter/interpreter.hpp>  // for Interpreter
#include <components/misc/stringops.hpp>  // for StringUtils
#include <components/interpreter/types.hpp>  // for Type_Code, etc

#include "../interpretercontext.hpp"

namespace MWScriptExtensions
{
    void activate(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000075;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000244;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void additem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca000076;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000077;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void addsoulgem(std::string arg0, std::string arg1, std::string arg2)
    {
        Interpreter::Type_Code codeword = 0xca0001f3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001f4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg2));
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void addspell(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000147;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000148;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void addtolevcreature(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fb;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void addtolevitem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void addtopic(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00013a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aiactivate(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xc2001e00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001f00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aiescort(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5, Interpreter::Type_Integer arg6)
    {
        Interpreter::Type_Code codeword = 0xc2000200;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2000300;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 7;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aiescortcell(std::string arg0, std::string arg1, std::string arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5, Interpreter::Type_Float arg6, Interpreter::Type_Integer arg7)
    {
        Interpreter::Type_Code codeword = 0xc2002000;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002100;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 8;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg2));
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aifollow(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5, Interpreter::Type_Integer arg6, Interpreter::Type_Integer arg7, Interpreter::Type_Integer arg8, Interpreter::Type_Integer arg9, Interpreter::Type_Integer arg10, Interpreter::Type_Integer arg11, Interpreter::Type_Integer arg12, Interpreter::Type_Integer arg13)
    {
        Interpreter::Type_Code codeword = 0xc2002200;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002300;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 14;
        uint optionalArgCount = 8;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg13!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg13);
            argumentsPassed++;
        }
        if (arg12!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg12);
            argumentsPassed++;
        }
        if (arg11!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg11);
            argumentsPassed++;
        }
        if (arg10!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aifollowcell(std::string arg0, std::string arg1, std::string arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5, Interpreter::Type_Float arg6, Interpreter::Type_Integer arg7)
    {
        Interpreter::Type_Code codeword = 0xc2002400;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002500;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 8;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg2));
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aitravel(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Integer arg4)
    {
        Interpreter::Type_Code codeword = 0xc2000000;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2000100;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 5;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg4!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void aiwander(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Integer arg4, Interpreter::Type_Integer arg5, Interpreter::Type_Integer arg6, Interpreter::Type_Integer arg7, Interpreter::Type_Integer arg8, Interpreter::Type_Integer arg9, Interpreter::Type_Integer arg10, Interpreter::Type_Integer arg11, Interpreter::Type_Integer arg12, Interpreter::Type_Integer arg13)
    {
        Interpreter::Type_Code codeword = 0xc2001000;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001100;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 14;
        uint optionalArgCount = 10;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg13!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg13);
            argumentsPassed++;
        }
        if (arg12!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg12);
            argumentsPassed++;
        }
        if (arg11!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg11);
            argumentsPassed++;
        }
        if (arg10!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void bc(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2002d00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002e00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void becomewerewolf(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000217;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000218;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void betacomment(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2002d00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002e00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void cast(std::string arg0, std::string arg1, std::string arg2)
    {
        Interpreter::Type_Code codeword = 0xca000227;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000228;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg2!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg2);
            argumentsPassed++;
        }
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer cellchanged()
    {
        Interpreter::Type_Code codeword = 0xca000000;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void centeroncell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000026;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void centeronexterior(Interpreter::Type_Integer arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000226;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void changeweather(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000140;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void choice(std::string arg0, Interpreter::Type_Integer arg1, std::string arg2, Interpreter::Type_Integer arg3, std::string arg4, Interpreter::Type_Integer arg5, std::string arg6, Interpreter::Type_Integer arg7, std::string arg8, Interpreter::Type_Integer arg9, std::string arg10, Interpreter::Type_Integer arg11, std::string arg12, Interpreter::Type_Integer arg13, std::string arg14, Interpreter::Type_Integer arg15, std::string arg16, Interpreter::Type_Integer arg17, std::string arg18, Interpreter::Type_Integer arg19, std::string arg20, Interpreter::Type_Integer arg21, std::string arg22, Interpreter::Type_Integer arg23, std::string arg24, Interpreter::Type_Integer arg25, std::string arg26, Interpreter::Type_Integer arg27, std::string arg28, Interpreter::Type_Integer arg29, std::string arg30, Interpreter::Type_Integer arg31, std::string arg32, Interpreter::Type_Integer arg33, std::string arg34, Interpreter::Type_Integer arg35, std::string arg36, Interpreter::Type_Integer arg37, std::string arg38, Interpreter::Type_Integer arg39, std::string arg40, Interpreter::Type_Integer arg41, std::string arg42, Interpreter::Type_Integer arg43, std::string arg44, Interpreter::Type_Integer arg45, std::string arg46, Interpreter::Type_Integer arg47)
    {
        Interpreter::Type_Code codeword = 0xc2000a00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 48;
        uint optionalArgCount = 48;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg47!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg47);
            argumentsPassed++;
        }
                if (arg46!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg46);
            argumentsPassed++;
        }
        if (arg45!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg45);
            argumentsPassed++;
        }
                if (arg44!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg44);
            argumentsPassed++;
        }
        if (arg43!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg43);
            argumentsPassed++;
        }
                if (arg42!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg42);
            argumentsPassed++;
        }
        if (arg41!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg41);
            argumentsPassed++;
        }
                if (arg40!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg40);
            argumentsPassed++;
        }
        if (arg39!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg39);
            argumentsPassed++;
        }
                if (arg38!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg38);
            argumentsPassed++;
        }
        if (arg37!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg37);
            argumentsPassed++;
        }
                if (arg36!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg36);
            argumentsPassed++;
        }
        if (arg35!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg35);
            argumentsPassed++;
        }
                if (arg34!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg34);
            argumentsPassed++;
        }
        if (arg33!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg33);
            argumentsPassed++;
        }
                if (arg32!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg32);
            argumentsPassed++;
        }
        if (arg31!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg31);
            argumentsPassed++;
        }
                if (arg30!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg30);
            argumentsPassed++;
        }
        if (arg29!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg29);
            argumentsPassed++;
        }
                if (arg28!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg28);
            argumentsPassed++;
        }
        if (arg27!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg27);
            argumentsPassed++;
        }
                if (arg26!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg26);
            argumentsPassed++;
        }
        if (arg25!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg25);
            argumentsPassed++;
        }
                if (arg24!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg24);
            argumentsPassed++;
        }
        if (arg23!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg23);
            argumentsPassed++;
        }
                if (arg22!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg22);
            argumentsPassed++;
        }
        if (arg21!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg21);
            argumentsPassed++;
        }
                if (arg20!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg20);
            argumentsPassed++;
        }
        if (arg19!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg19);
            argumentsPassed++;
        }
                if (arg18!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg18);
            argumentsPassed++;
        }
        if (arg17!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg17);
            argumentsPassed++;
        }
                if (arg16!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg16);
            argumentsPassed++;
        }
        if (arg15!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg15);
            argumentsPassed++;
        }
                if (arg14!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg14);
            argumentsPassed++;
        }
        if (arg13!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg13);
            argumentsPassed++;
        }
                if (arg12!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg12);
            argumentsPassed++;
        }
        if (arg11!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg11);
            argumentsPassed++;
        }
                if (arg10!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
                if (arg8!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
                if (arg6!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
                if (arg4!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
                if (arg2!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void clearforcejump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000258;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000259;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void clearforcemovejump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00025c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00025d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void clearforcerun(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000154;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000155;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void clearforcesneak(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000158;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000159;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void clearinfoactor(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000245;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000246;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void coc(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000026;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void coe(Interpreter::Type_Integer arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000226;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disablelevitation()
    {
        Interpreter::Type_Code codeword = 0xca000220;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableplayercontrols()
    {
        Interpreter::Type_Code codeword = 0xca000085;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableplayerfighting()
    {
        Interpreter::Type_Code codeword = 0xca000086;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableplayerjumping()
    {
        Interpreter::Type_Code codeword = 0xca000087;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableplayerlooking()
    {
        Interpreter::Type_Code codeword = 0xca000088;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableplayermagic()
    {
        Interpreter::Type_Code codeword = 0xca000089;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableplayerviewswitch()
    {
        Interpreter::Type_Code codeword = 0xca00008a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disableteleporting()
    {
        Interpreter::Type_Code codeword = 0xca000215;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void disablevanitymode()
    {
        Interpreter::Type_Code codeword = 0xca00008b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void dontsaveobject()
    {
        Interpreter::Type_Code codeword = 0xca000153;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void drop(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0001f8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001f9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void dropsoulgem(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001fa;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001fb;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablebirthmenu()
    {
        Interpreter::Type_Code codeword = 0xca00000e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableclassmenu()
    {
        Interpreter::Type_Code codeword = 0xca00000f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableinventorymenu()
    {
        Interpreter::Type_Code codeword = 0xca000013;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablelevelupmenu()
    {
        Interpreter::Type_Code codeword = 0xca000300;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablelevitation()
    {
        Interpreter::Type_Code codeword = 0xca000221;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablemagicmenu()
    {
        Interpreter::Type_Code codeword = 0xca000014;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablemapmenu()
    {
        Interpreter::Type_Code codeword = 0xca000015;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablenamemenu()
    {
        Interpreter::Type_Code codeword = 0xca000010;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableplayercontrols()
    {
        Interpreter::Type_Code codeword = 0xca00007e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableplayerfighting()
    {
        Interpreter::Type_Code codeword = 0xca00007f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableplayerjumping()
    {
        Interpreter::Type_Code codeword = 0xca000080;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableplayerlooking()
    {
        Interpreter::Type_Code codeword = 0xca000081;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableplayermagic()
    {
        Interpreter::Type_Code codeword = 0xca000082;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableplayerviewswitch()
    {
        Interpreter::Type_Code codeword = 0xca000083;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableracemenu()
    {
        Interpreter::Type_Code codeword = 0xca000011;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablerest()
    {
        Interpreter::Type_Code codeword = 0xca000017;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablestatreviewmenu()
    {
        Interpreter::Type_Code codeword = 0xca000012;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablestatsmenu()
    {
        Interpreter::Type_Code codeword = 0xca000016;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enableteleporting()
    {
        Interpreter::Type_Code codeword = 0xca000216;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void enablevanitymode()
    {
        Interpreter::Type_Code codeword = 0xca000084;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void equip(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001b3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001b4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void explodespell(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000229;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00022a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void externalscriptreturn()
    {
        Interpreter::Type_Code codeword = 0xca000303;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void face(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca00024c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00024d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void fadein(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00013c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void fadeout(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca00013d;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void fadeto(Interpreter::Type_Float arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00013e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void fall(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00020a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00020b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void fillmap()
    {
        Interpreter::Type_Code codeword = 0xca0001a1;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void fixme()
    {
        Interpreter::Type_Code codeword = 0xca000302;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void forcegreeting(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00014f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000150;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void forcejump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00025a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00025b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void forcemovejump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00025e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00025f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void forcerun(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000156;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000157;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void forcesneak(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00015a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00015b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer getacrobatics(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a2;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000bd;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getagility(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00002a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000032;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getaipackagedone(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00007c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00007d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getalarm(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001c5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001c6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getalchemy(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00009e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getalteration(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000099;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getangle(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00016a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00016b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getarmorbonus(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000274;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00028c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getarmorer(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00008f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000aa;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getarmortype(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001d1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001d2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getathletics(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000096;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getattackbonus(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00027a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000292;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getattacked(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001d3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001d4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getaxe(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000094;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000af;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getblightdisease(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001aa;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001ab;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getblindness(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000277;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00028f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getblock(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00008e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000a9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getbluntweapon(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000092;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ad;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getbuttonpressed()
    {
        Interpreter::Type_Code codeword = 0xca000137;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getcastpenalty(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000275;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00028d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getchameleon(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00026f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000287;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getcollidingactor(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000252;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000253;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getcollidingpc(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000250;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000251;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getcommondisease(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001a9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getconjuration(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00009b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getcurrentaipackage(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ef;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001f0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getcurrenttime()
    {
        Interpreter::Type_Code codeword = 0xca0001dd;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getcurrentweather()
    {
        Interpreter::Type_Code codeword = 0xca00013f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getdeadcount(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a3;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getdefendbonus(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00027b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000293;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getdestruction(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000098;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getdetected(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001f1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001f2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getdisposition(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001a7;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer geteffect(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001cf;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001d0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getenchant(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000097;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getendurance(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00002c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000034;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getfactionreaction(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000243;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getfatigue(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000059;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00005c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Float getfatiguegetratio(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000071;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000074;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getfight(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001c1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001c2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getflee(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001c3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001c4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getflying(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000273;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00028b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getforcejump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000260;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000261;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getforcemovejump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000262;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000263;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getforcerun(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001cb;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001cd;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getforcesneak(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001cc;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001ce;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer gethandtohand(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000c3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float gethealth(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000057;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00005a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Float gethealthgetratio(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00006f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000072;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getheavyarmor(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000091;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ac;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer gethello(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001bf;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001c0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getillusion(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00009a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b5;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getintelligence(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000028;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000030;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getinterior()
    {
        Interpreter::Type_Code codeword = 0xca000131;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getinvisible(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000279;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000291;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getitemcount(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000078;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000079;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getjournalindex(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000135;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getlevel(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00018c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00018d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getlightarmor(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000be;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getlineofsight(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000222;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000223;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getlocked(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001c7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001c8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getlongblade(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000093;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ae;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getlos(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000222;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000223;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getluck(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00002e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000036;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getmagicka(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000058;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00005b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Float getmagickagetratio(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000070;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000073;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getmarksman(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000c0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getmasserphase()
    {
        Interpreter::Type_Code codeword = 0xca000024;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getmediumarmor(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000090;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ab;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getmercantile(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000c1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getmysticism(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00009c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b7;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getparalysis(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000278;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000290;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpccell(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000136;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getpccrimelevel()
    {
        Interpreter::Type_Code codeword = 0xca0001ec;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getpcfacrep(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001200;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001300;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpcinjail()
    {
        Interpreter::Type_Code codeword = 0xca00023e;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpcjumping()
    {
        Interpreter::Type_Code codeword = 0xca000233;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpcrank(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2000e00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2000f00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpcrunning()
    {
        Interpreter::Type_Code codeword = 0xca0001c9;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpcsleep()
    {
        Interpreter::Type_Code codeword = 0xca00019f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpcsneaking()
    {
        Interpreter::Type_Code codeword = 0xca0001ca;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpctraveling()
    {
        Interpreter::Type_Code codeword = 0xca00023f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getpersonality(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00002d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000035;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getplayercontrolsdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000175;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getplayerfightingdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000176;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getplayerjumpingdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000177;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getplayerlookingdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000178;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getplayermagicdisabled()
    {
        Interpreter::Type_Code codeword = 0xca000179;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getplayerviewswitchdisabled()
    {
        Interpreter::Type_Code codeword = 0xca00017a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getpos(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000190;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000191;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getrace(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001d9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001da;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getreputation(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001b1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001b2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistblight(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000269;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000281;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistcorprus(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00026a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000282;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistdisease(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000268;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000280;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistfire(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000265;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00027d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistfrost(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000266;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00027e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistmagicka(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000264;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00027c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistnormalweapons(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00026d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000285;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistparalysis(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00026c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000284;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistpoison(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00026b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000283;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getresistshock(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000267;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00027f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getrestoration(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00009d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getscale(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000168;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000169;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getsecundaphase()
    {
        Interpreter::Type_Code codeword = 0xca000025;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getsecurity(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a0;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000bb;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getshortblade(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000bf;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getsilence(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000276;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00028e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getsneak(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000bc;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getsoundplaying(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00000b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000020;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getspear(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000095;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000b0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getspeechcraft(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0000a7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000c2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getspeed(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00002b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000033;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getspell(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00014b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00014c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getspelleffects(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001db;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001dc;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getspellreadied(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000231;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000232;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getsquareroot(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001e7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getstandingactor(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00020e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00020f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getstandingpc(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00020c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00020d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getstartingangle(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000210;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000211;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Float getstartingpos(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000194;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000195;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getstat(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00024e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00024f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getstrength(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000027;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00002f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getsuperjump(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000272;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00028a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getswimspeed(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000271;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000289;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer gettarget(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000238;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000239;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getunarmored(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00009f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ba;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getvanitymodedisabled()
    {
        Interpreter::Type_Code codeword = 0xca00017b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getwaterbreathing(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00026e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000286;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getwaterlevel()
    {
        Interpreter::Type_Code codeword = 0xca000141;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    Interpreter::Type_Integer getwaterwalking(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000270;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000288;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getweapondrawn(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001d7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001d8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getweapontype(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001e0;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001e1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getwerewolfkills()
    {
        Interpreter::Type_Code codeword = 0xca0001e2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer getwillpower(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000029;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000031;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Float getwindspeed()
    {
        Interpreter::Type_Code codeword = 0xca000212;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mFloat;
    }
    void goodbye()
    {
        Interpreter::Type_Code codeword = 0xca000152;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void gotojail()
    {
        Interpreter::Type_Code codeword = 0xca000235;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer hasitemequipped(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001d5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001d6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer hassoulgem(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001de;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001df;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer hitattemptonme(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002f9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002fa;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer hitonme(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000213;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000214;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void hurtcollidingactor(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000256;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000257;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void hurtstandingactor(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000254;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000255;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer iswerewolf(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001fd;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001fe;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void journal(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca000133;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00030b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void lock(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xc2000400;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2000500;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void loopgroup(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2, Interpreter::Type_Integer arg3)
    {
        Interpreter::Type_Code codeword = 0xc2000800;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2000900;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void lowerrank(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ea;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001eb;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void menutest(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xc2002c00;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modacrobatics(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00010e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000129;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modagility(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00004a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000052;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modalarm(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001bd;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001be;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modalchemy(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00010a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000125;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modalteration(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000105;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000120;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modarmorbonus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ec;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modarmorer(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000fb;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000116;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modathletics(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000102;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00011d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modattackbonus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002da;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002f2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modaxe(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000100;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00011b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modblindness(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ef;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modblock(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000fa;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000115;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modbluntweapon(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000fe;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000119;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modcastpenalty(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ed;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modchameleon(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002cf;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e7;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modconjuration(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000107;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000122;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modcurrentfatigue(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00006b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00006e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modcurrenthealth(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000069;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00006c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modcurrentmagicka(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00006a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00006d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void moddefendbonus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002db;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002f3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void moddestruction(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000104;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00011f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void moddisposition(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00014d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00014e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modenchant(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000103;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00011e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modendurance(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00004c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000054;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modfactionreaction(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca000242;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modfatigue(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000065;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000068;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modfight(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001b9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001ba;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modflee(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001bb;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001bc;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modflying(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002eb;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modhandtohand(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000114;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00012f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modhealth(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000063;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000066;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modheavyarmor(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000fd;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000118;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modhello(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001b7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001b8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modillusion(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000106;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000121;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modintelligence(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000048;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000050;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modinvisible(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002f1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modlightarmor(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00010f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00012a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modlongblade(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000ff;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00011a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modluck(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00004e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000056;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modmagicka(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000064;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000067;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modmarksman(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000111;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00012c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modmediumarmor(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000fc;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000117;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modmercantile(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000112;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00012d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modmysticism(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000108;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000123;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modparalysis(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002f0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modpccrimelevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ee;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modpcfacrep(std::string arg0, Interpreter::Type_Integer arg1, std::string arg2)
    {
        Interpreter::Type_Code codeword = 0xc2001600;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001700;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg2));
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modpersonality(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00004d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000055;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modregion(std::string arg0, Interpreter::Type_Integer arg1, Interpreter::Type_Integer arg2, Interpreter::Type_Integer arg3, Interpreter::Type_Integer arg4, Interpreter::Type_Integer arg5, Interpreter::Type_Integer arg6, Interpreter::Type_Integer arg7, Interpreter::Type_Integer arg8, Interpreter::Type_Integer arg9, Interpreter::Type_Integer arg10)
    {
        Interpreter::Type_Code codeword = 0xc2002600;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 11;
        uint optionalArgCount = 10;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg10!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg10);
            argumentsPassed++;
        }
        if (arg9!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg9);
            argumentsPassed++;
        }
        if (arg8!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg8);
            argumentsPassed++;
        }
        if (arg7!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg7);
            argumentsPassed++;
        }
        if (arg6!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg6);
            argumentsPassed++;
        }
        if (arg5!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modreputation(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001ae;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001b0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistblight(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002c9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistcorprus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002ca;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistdisease(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002c8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistfire(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002c5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002dd;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistfrost(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002c6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002de;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistmagicka(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002c4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002dc;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistnormalweapons(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002cd;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e5;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistparalysis(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002cc;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistpoison(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002cb;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modresistshock(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002c7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002df;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modrestoration(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000109;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000124;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modscale(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001e3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001e4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modsecurity(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00010c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000127;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modshortblade(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000110;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00012b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modsilence(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ee;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modsneak(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00010d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000128;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modspear(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000101;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00011c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modspeechcraft(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000113;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00012e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modspeed(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00004b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000053;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modstrength(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000047;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00004f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modsuperjump(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d2;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ea;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modswimspeed(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modunarmored(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00010b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000126;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modwaterbreathing(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002ce;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modwaterlevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000143;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modwaterwalking(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002d0;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002e8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void modwillpower(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000049;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000051;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void move(std::string arg0, std::string arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000206;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000207;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void moveworld(std::string arg0, std::string arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000208;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000209;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer onactivate(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00000d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000306;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer ondeath(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001fc;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000205;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer onknockout(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000240;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000241;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    Interpreter::Type_Integer onmurder(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000249;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00024a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void ori(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2002d00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002e00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void payfine()
    {
        Interpreter::Type_Code codeword = 0xca000236;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void payfinethief()
    {
        Interpreter::Type_Code codeword = 0xca000237;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void pcclearexpelled(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001c00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001d00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void pcexpell(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001a00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001b00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer pcexpelled(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2001800;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001900;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void pcforce1stperson()
    {
        Interpreter::Type_Code codeword = 0xca0002f6;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void pcforce3rdperson()
    {
        Interpreter::Type_Code codeword = 0xca0002f7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer pcget3rdperson()
    {
        Interpreter::Type_Code codeword = 0xca0002f8;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void pcjoinfaction(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2000d00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002b00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void pclowerrank(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2000c00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002a00;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void pcraiserank(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xc2000b00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002900;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void placeatme(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2, Interpreter::Type_Float arg3, Interpreter::Type_Integer arg4)
    {
        Interpreter::Type_Code codeword = 0xca00019d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00019e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 5;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg4!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void placeatpc(std::string arg0, Interpreter::Type_Integer arg1, Interpreter::Type_Float arg2, Interpreter::Type_Integer arg3)
    {
        Interpreter::Type_Code codeword = 0xca00019c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void placeitem(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4)
    {
        Interpreter::Type_Code codeword = 0xca00019b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 5;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void placeitemcell(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, Interpreter::Type_Float arg5)
    {
        Interpreter::Type_Code codeword = 0xca00019a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 6;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg5!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg5);
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playbink(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001f7;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playgroup(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xc2000600;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2000700;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playloopsound3d(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000008;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00001d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playloopsound3dvp(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3)
    {
        Interpreter::Type_Code codeword = 0xca000009;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00001e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playsound(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000004;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playsound3d(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000006;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00001b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playsound3dvp(std::string arg0, std::string arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3)
    {
        Interpreter::Type_Code codeword = 0xca000007;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00001c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 4;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void playsoundvp(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000005;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void position(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4)
    {
        Interpreter::Type_Code codeword = 0xca000196;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000197;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 5;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void positioncell(std::string arg0, Interpreter::Type_Float arg1, Interpreter::Type_Float arg2, Interpreter::Type_Float arg3, Interpreter::Type_Float arg4, std::string arg5)
    {
        Interpreter::Type_Code codeword = 0xca000198;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000199;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 6;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg5!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg5));
            argumentsPassed++;
        }
        if (arg4!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg4);
            argumentsPassed++;
        }
        if (arg3!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg3);
            argumentsPassed++;
        }
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void ra()
    {
        Interpreter::Type_Code codeword = 0xca0002f4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void raiserank(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001e8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001e9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removeeffects(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00022d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00022e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removefromlevcreature(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fc;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removefromlevitem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002fe;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removeitem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca00007a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00007b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removesoulgem(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xc2002700;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2002800;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removespell(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000149;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00014a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void removespelleffects(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00022b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00022c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void resetactors()
    {
        Interpreter::Type_Code codeword = 0xca0002f4;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void resurrect(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00022f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000230;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void rotate(std::string arg0, std::string arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca0001ff;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000200;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void rotateworld(std::string arg0, std::string arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000201;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000202;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer samefaction(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001b5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001b6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void say(std::string arg0, std::string arg1, std::string arg2)
    {
        Interpreter::Type_Code codeword = 0xca000001;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000019;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg2!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg2);
            argumentsPassed++;
        }
                if (arg1!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer saydone(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000002;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00001a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
    void setacrobatics(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setagility(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00003a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000042;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setalarm(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000162;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000163;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setalchemy(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ef;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setalteration(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000cf;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ea;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setangle(std::string arg0, std::string arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000166;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000167;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setarmorbonus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002bc;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setarmorer(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000c5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setathletics(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000cc;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e7;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setatstart(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000203;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000204;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setattackbonus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002aa;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002c2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setaxe(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000ca;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e5;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setblindness(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002bf;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setblock(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000c4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000df;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setbluntweapon(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000c8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setcastpenalty(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002bd;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setchameleon(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00029f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b7;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setconjuration(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ec;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setdefendbonus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002ab;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002c3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setdelete(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001e5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001e6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setdestruction(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000ce;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setdisposition(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001a4;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001a5;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setenchant(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000cd;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setendurance(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00003c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000044;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setfactionreaction(std::string arg0, std::string arg1, Interpreter::Type_Integer arg2)
    {
        Interpreter::Type_Code codeword = 0xca0002ff;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setfatigue(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00005f;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000062;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setfight(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00015e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00015f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setflee(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000160;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000161;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setflying(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002bb;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void sethandtohand(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000de;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void sethealth(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00005d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000060;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setheavyarmor(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000c7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void sethello(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00015c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00015d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setillusion(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d0;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000eb;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setintelligence(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000038;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000040;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setinvisible(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002c1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setjournalindex(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000134;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg0));
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setlevel(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00018e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00018f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setlightarmor(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setlongblade(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000c9;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setluck(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00003e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000046;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setmagicka(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca00005e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000061;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setmarksman(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000db;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setmediumarmor(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000c6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setmercantile(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000dc;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f7;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setmysticism(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d2;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ed;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setnavmeshnumber(Interpreter::Type_Integer arg0)
    {
        Interpreter::Type_Code codeword = 0xca00030a;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setparalysis(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a8;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002c0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setpccrimelevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001ed;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setpcfacrep(std::string arg0, Interpreter::Type_Integer arg1, std::string arg2)
    {
        Interpreter::Type_Code codeword = 0xc2001400;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2001500;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg2));
            argumentsPassed++;
        }
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setpersonality(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00003d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000045;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setpos(std::string arg0, std::string arg1, Interpreter::Type_Float arg2)
    {
        Interpreter::Type_Code codeword = 0xca000192;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000193;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 3;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg2!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg2);
            argumentsPassed++;
        }
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setreputation(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0001ad;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0001af;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistblight(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000299;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistcorprus(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00029a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistdisease(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000298;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistfire(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000295;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ad;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistfrost(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000296;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ae;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistmagicka(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000294;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ac;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistnormalweapons(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00029d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b5;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistparalysis(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00029c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b4;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistpoison(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00029b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b3;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setresistshock(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000297;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002af;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setrestoration(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d3;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000ee;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setscale(std::string arg0, Interpreter::Type_Float arg1)
    {
        Interpreter::Type_Code codeword = 0xca000164;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000165;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setsecurity(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f1;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setshortblade(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000da;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f5;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setsilence(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a6;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002be;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setsneak(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d7;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f2;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setspear(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000cb;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000e6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setspeechcraft(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000dd;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setspeed(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00003b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000043;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setstrength(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000037;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00003f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setsuperjump(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a2;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002ba;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setswimspeed(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a1;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b9;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setunarmored(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0000d5;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0000f0;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setwaterbreathing(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca00029e;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b6;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setwaterlevel(Interpreter::Type_Float arg0)
    {
        Interpreter::Type_Code codeword = 0xca000142;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0!=-123456)
        {
            Compiler::Generator::pushFloat(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setwaterwalking(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca0002a0;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca0002b8;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setwerewolfacrobatics(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00021b;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00021c;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void setwillpower(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xca000039;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000041;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void show(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca000304;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000305;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void showmap(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca0001a0;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void showrestmenu(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000018;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000234;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void showscenegraph(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xc2002f00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2003000;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void showvars(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00021d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00021e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void skipanim(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000138;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca000139;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void ssg(std::string arg0, Interpreter::Type_Integer arg1)
    {
        Interpreter::Type_Code codeword = 0xc2002f00;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xc2003000;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 1;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!=-123456)
        {
            Compiler::Generator::pushInt(code, literals, arg1);
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void startcombat(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00023a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00023b;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void startexternalscript(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000302;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void stopcombat(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00023c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00023d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void stopsound(std::string arg0, std::string arg1)
    {
        Interpreter::Type_Code codeword = 0xca00000a;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00001f;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 2;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg1!="OPTIONAL_FLAG")
        {
            Compiler::Generator::pushString(code, literals, Misc::StringUtils::lowerCase (arg1));
            argumentsPassed++;
        }
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void streammusic(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000003;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
                if (arg0!="OPTIONAL_FLAG" )
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void sv(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00021d;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00021e;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tai()
    {
        Interpreter::Type_Code codeword = 0xca000224;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tap()
    {
        Interpreter::Type_Code codeword = 0xca000309;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tb()
    {
        Interpreter::Type_Code codeword = 0xca000307;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tcb()
    {
        Interpreter::Type_Code codeword = 0xca0001ac;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tcg()
    {
        Interpreter::Type_Code codeword = 0xca000132;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tcl()
    {
        Interpreter::Type_Code codeword = 0xca000130;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tfh()
    {
        Interpreter::Type_Code codeword = 0xca000151;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tfow()
    {
        Interpreter::Type_Code codeword = 0xca000145;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tgm()
    {
        Interpreter::Type_Code codeword = 0xca00021f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tm()
    {
        Interpreter::Type_Code codeword = 0xca00024b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void toggleactorspaths()
    {
        Interpreter::Type_Code codeword = 0xca000309;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void toggleai()
    {
        Interpreter::Type_Code codeword = 0xca000224;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void toggleborders()
    {
        Interpreter::Type_Code codeword = 0xca000307;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglecollision()
    {
        Interpreter::Type_Code codeword = 0xca000130;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglecollisionboxes()
    {
        Interpreter::Type_Code codeword = 0xca0001ac;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglecollisiongrid()
    {
        Interpreter::Type_Code codeword = 0xca000132;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglefogofwar()
    {
        Interpreter::Type_Code codeword = 0xca000145;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglefullhelp()
    {
        Interpreter::Type_Code codeword = 0xca000151;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglegodmode()
    {
        Interpreter::Type_Code codeword = 0xca00021f;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglemenus()
    {
        Interpreter::Type_Code codeword = 0xca00024b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglenavmesh()
    {
        Interpreter::Type_Code codeword = 0xca000308;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglepathgrid()
    {
        Interpreter::Type_Code codeword = 0xca000146;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglescripts()
    {
        Interpreter::Type_Code codeword = 0xca000301;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglesky()
    {
        Interpreter::Type_Code codeword = 0xca000021;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglevanitymode()
    {
        Interpreter::Type_Code codeword = 0xca000174;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglewater()
    {
        Interpreter::Type_Code codeword = 0xca000144;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void togglewireframe()
    {
        Interpreter::Type_Code codeword = 0xca00013b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void toggleworld()
    {
        Interpreter::Type_Code codeword = 0xca0002f5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tpg()
    {
        Interpreter::Type_Code codeword = 0xca000146;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void ts()
    {
        Interpreter::Type_Code codeword = 0xca000021;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void turnmoonred()
    {
        Interpreter::Type_Code codeword = 0xca000023;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void turnmoonwhite()
    {
        Interpreter::Type_Code codeword = 0xca000022;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tvm()
    {
        Interpreter::Type_Code codeword = 0xca000174;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void tw()
    {
        Interpreter::Type_Code codeword = 0xca0002f5;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void twa()
    {
        Interpreter::Type_Code codeword = 0xca000144;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void twf()
    {
        Interpreter::Type_Code codeword = 0xca00013b;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void undowerewolf(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca000219;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00021a;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void unlock(std::string arg0)
    {
        Interpreter::Type_Code codeword = 0xca00008c;//codeword without arguments
        Compiler::Literals literals;
        if(arg0!="self") codeword = 0xca00008d;//codeword without arguments
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 1;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        if (arg0 !="self")
        {
            Compiler::Generator::pushString(code, literals, arg0);
            argumentsPassed++;
        }
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    void wakeuppc()
    {
        Interpreter::Type_Code codeword = 0xca0001a2;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return;
    }
    Interpreter::Type_Integer xbox()
    {
        Interpreter::Type_Code codeword = 0xca00000c;//codeword without arguments
        Compiler::Literals literals;
        std::vector<Interpreter::Type_Code> code;
        uint argCount = 0;
        uint optionalArgCount = 0;
        uint argumentsPassed = 0;
        uint optionalArgumentsPassed = 0;
        optionalArgumentsPassed = argumentsPassed-(argCount-optionalArgCount);
        // adds number of arguments as argument to the codeword, similar to how generateInstructionCode does it
        if (argumentsPassed > 0) codeword= codeword | (optionalArgumentsPassed & 0xff);
        code.push_back(codeword);
        code.push_back(0xc8000000 | Compiler::ExternalScript::opcodeExternalScriptReturn);//segment 5 code
        //now append codeword to code, append literals to code, create header words and place at head of code see Output::getCode()
        std::vector<Interpreter::Type_Code> codeblock;
        codeblock.push_back (static_cast<Interpreter::Type_Code> (code.size()));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getIntegerSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getFloatSize()/4));
        codeblock.push_back (static_cast<Interpreter::Type_Code> (literals.getStringSize()/4));
        std::copy (code.begin(), code.end(), std::back_inserter (codeblock));
        literals.append(codeblock);
        for( std::vector<Interpreter::Type_Code>::const_iterator i = codeblock.begin(); i != codeblock.end(); ++i)
        interpreter.run(&codeblock[0], codeblock.size(), *context);//todo - get the runtime stack!
        return stackReturn.mInteger;
    }
}

