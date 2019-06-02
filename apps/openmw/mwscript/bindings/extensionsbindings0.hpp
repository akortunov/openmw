#ifndef EXTENSIONSBINDINGS0_HPP
#define EXTENSIONSBINDINGS0_HPP

#include <string>

namespace MWScriptExtensions
{
    void omwset(std::string name, float value);
    float omwget(std::string name);
    void omwcall(std::string command);
}
#endif
