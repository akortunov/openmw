#ifndef OPENMW_COMPONENTS_DETOURNAVIGATOR_DEBUG_H
#define OPENMW_COMPONENTS_DETOURNAVIGATOR_DEBUG_H

#include "tilebounds.hpp"

#include <osg/io_utils>

#include <components/bullethelpers/operators.hpp>
#include <components/misc/guarded.hpp>

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <thread>

class dtNavMesh;

namespace DetourNavigator
{
    inline std::ostream& operator <<(std::ostream& stream, const TileBounds& value)
    {
        return stream << "TileBounds {" << value.mMin << ", " << value.mMax << "}";
    }

    class RecastMesh;

    inline std::ostream& operator <<(std::ostream& stream, const std::chrono::steady_clock::time_point& value)
    {
        using float_s = std::chrono::duration<float, std::ratio<1>>;
        return stream << std::fixed << std::setprecision(4)
                      << std::chrono::duration_cast<float_s>(value.time_since_epoch()).count();
    }

    void writeToFile(const RecastMesh& recastMesh, const std::string& pathPrefix, const std::string& revision);
    void writeToFile(const dtNavMesh& navMesh, const std::string& pathPrefix, const std::string& revision);
}

#endif
