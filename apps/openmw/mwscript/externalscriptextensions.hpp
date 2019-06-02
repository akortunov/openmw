#ifndef GAME_SCRIPT_EXTERNALSCRIPTEXTENSIONS_HPP
#define GAME_SCRIPT_EXTERNALSCRIPTEXTENSIONS_HPP

namespace Compiler
{
    class Extensions;
}

namespace Interpreter
{
    class Interpreter;
}

namespace MWScript
{
    namespace ExternalScript
    {
        void installOpcodes (Interpreter::Interpreter& interpreter);
    }
}

#endif
