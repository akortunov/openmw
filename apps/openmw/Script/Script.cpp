//
// Created by koncord on 19.03.16.
//

#include "Script.hpp"

#if defined (ENABLE_LUA)
#include "LangLua/LangLua.hpp"
#endif

using namespace std;

Script::ScriptList Script::scripts;
std::string Script::moddir;

Script::Script(const char *path)
{

#if defined (ENABLE_LUA)
    FILE *file = fopen(path, "rb");

    if (!file)
        throw runtime_error("Script not found: " + string(path));

    fclose(file);

    if (strstr(path, ".lua") || strstr(path, ".t"))
    {
        lang = new LangLua();
        script_type = SCRIPT_LUA;
    }
    else
        throw runtime_error("Script type not recognized: " + string(path));

    try
    {
        lang->LoadProgram(path);
    }
    catch (...)
    {
        lang->FreeProgram();
        throw;
    }
#endif
}


Script::~Script()
{
    lang->FreeProgram();

    delete lang;
}

void Script::LoadScripts(char *scripts, const char *base)
{
    char *token = strtok(scripts, ",");

    try
    {
        while (token)
        {
            char path[4096];
            snprintf(path, sizeof(path), Utils::convertPath("%s/%s/%s").c_str(), base, "scripts", token);
            Script::scripts.emplace_back(new Script(path));
            token = strtok(nullptr, ",");
        }
    }
    catch (...)
    {
        UnloadScripts();
        throw;
    }
}

void Script::UnloadScripts()
{
    //Public::DeleteAll();
    scripts.clear();
}

void Script::LoadScript(const char *script, const char *base)
{
    char path[4096];
    snprintf(path, sizeof(path), Utils::convertPath("%s/%s/%s").c_str(), base, "scripts", script);
    Script::scripts.emplace_back(new Script(path));
}

void Script::SetModDir(const std::string &moddir)
{
    if (Script::moddir.empty()) // do not allow to change in runtime
        Script::moddir = moddir;
}

const char* Script::GetModDir()
{
    return moddir.c_str();
}
