#include "bindingsvars.hpp"

#include <stddef.h>                     // for NULL

#include <components/interpreter/interpreter.hpp>  // for Interpreter
#include <components/interpreter/types.hpp>  // for Type_Code, etc

namespace MWScriptExtensions
{
    Interpreter::Interpreter interpreter;
    lua_State *luaState=NULL;
    bool opcodesInstalled=false;
    bool pythonInitialized=false;
    MWScript::InterpreterContext *context=NULL;
    Interpreter::Data stackReturn;
}
