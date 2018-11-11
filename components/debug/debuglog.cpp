#include "debuglog.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h> //support for stdout logging
#include <spdlog/sinks/basic_file_sink.h> // support for basic file logging
#include <spdlog/fmt/ostr.h> // support for basic file logging

namespace Debug
{
    Level CurrentDebugLevel = Level::NoLevel;
}

void Log::LogImpl(std::string msg, Debug::Level level)
{
    spdlog::level::level_enum spdLevel;
    switch (level)
    {
        case Debug::Error:
            spdLevel = spdlog::level::err;
            break;
        case Debug::Warning:
            spdLevel = spdlog::level::warn;
            break;
        case Debug::Info:
            spdLevel = spdlog::level::info;
            break;
        default:
            spdLevel = spdlog::level::debug;
            break;
    }

    spdlog::get(Debug::Sink::Console)->log(spdLevel, msg);
    spdlog::get(Debug::Sink::GenericFile)->log(spdLevel, msg);
}

std::mutex Log::sLock;
