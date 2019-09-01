#include "Debug.hpp"

#include "../../mwbase/environment.hpp"
#include "../../mwbase/mechanicsmanager.hpp"
#include "../../mwbase/world.hpp"

void DebugFunctions::ToggleCollisions() noexcept
{
    MWBase::Environment::get().getWorld()->toggleCollisionMode();
}

void DebugFunctions::ToggleCollisionBoxes() noexcept
{
    MWBase::Environment::get().getWorld()->toggleRenderMode (MWRender::Render_CollisionDebug);
}

void DebugFunctions::ToggleWireframe() noexcept
{
    MWBase::Environment::get().getWorld()->toggleRenderMode (MWRender::Render_Wireframe);
}

void DebugFunctions::ToggleBorders() noexcept
{
    MWBase::Environment::get().getWorld()->toggleBorders();
}

void DebugFunctions::TogglePathgrid() noexcept
{
    MWBase::Environment::get().getWorld()->toggleRenderMode (MWRender::Render_Pathgrid);
}

void DebugFunctions::ToggleWater() noexcept
{
    MWBase::Environment::get().getWorld()->toggleWater();
}

void DebugFunctions::ToggleWorld() noexcept
{
    MWBase::Environment::get().getWorld()->toggleWorld();
}

void DebugFunctions::ToggleScripts() noexcept
{
    MWBase::Environment::get().getWorld()->toggleScripts();
}

void DebugFunctions::ToggleGodMode() noexcept
{
    MWBase::Environment::get().getWorld()->toggleGodMode();
}

void DebugFunctions::ToggleNavMesh() noexcept
{
    MWBase::Environment::get().getWorld()->toggleRenderMode (MWRender::Render_NavMesh);
}

void DebugFunctions::ToggleActorsPaths() noexcept
{
    MWBase::Environment::get().getWorld()->toggleRenderMode (MWRender::Render_ActorsPaths);
}

void DebugFunctions::ToggleAI() noexcept
{
    MWBase::Environment::get().getMechanicsManager()->toggleAI();
}

void DebugFunctions::SetNavMeshNumberToRender(const int count) noexcept
{
    if (count >= 0)
    {
        MWBase::Environment::get().getWorld()->setNavMeshNumberToRender(static_cast<std::size_t>(count));
    }
}
