#ifndef OPENMW_DEBUGAPI_HPP
#define OPENMW_DEBUGAPI_HPP

#define DEBUGAPI \
    {"ToggleCollisions",           DebugFunctions::ToggleCollisions},\
    {"ToggleCollisionBoxes",       DebugFunctions::ToggleCollisionBoxes},\
    {"ToggleWireframe",            DebugFunctions::ToggleWireframe},\
    {"ToggleBorders",              DebugFunctions::ToggleBorders},\
    {"TogglePathgrid",             DebugFunctions::TogglePathgrid},\
    {"ToggleWater",                DebugFunctions::ToggleWater},\
    {"ToggleWorld",                DebugFunctions::ToggleWorld},\
    {"ToggleScripts",              DebugFunctions::ToggleScripts},\
    {"ToggleGodMode",              DebugFunctions::ToggleGodMode},\
    {"ToggleNavMesh",              DebugFunctions::ToggleNavMesh},\
    {"ToggleActorsPaths",          DebugFunctions::ToggleActorsPaths},\
    {"ToggleAI",                   DebugFunctions::ToggleAI},\
    {"SetNavMeshNumberToRender",   DebugFunctions::SetNavMeshNumberToRender}

class DebugFunctions
{
public:

    static void ToggleCollisions() noexcept;

    static void ToggleCollisionBoxes() noexcept;

    static void ToggleWireframe() noexcept;

    static void ToggleBorders() noexcept;

    static void TogglePathgrid() noexcept;

    static void ToggleWater() noexcept;

    static void ToggleWorld() noexcept;

    static void ToggleScripts() noexcept;

    static void ToggleGodMode() noexcept;

    static void ToggleNavMesh() noexcept;

    static void ToggleActorsPaths() noexcept;

    static void ToggleAI() noexcept;

    static void SetNavMeshNumberToRender(const int count) noexcept;
};

#endif //OPENMW_DEBUGAPI_HPP
