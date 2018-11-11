#include "debuglog.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h> //support for stdout logging
#include <spdlog/sinks/basic_file_sink.h> // support for basic file logging
#include <spdlog/fmt/ostr.h> // support for basic file logging

namespace Debug
{
    Level CurrentDebugLevel = Level::NoLevel;
}

void Log::LogImpl(std::string msg, std::string sinkName, Debug::Level level)
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

    // Log to console and common log file, if the sink was not specified
    if (sinkName.empty())
    {
        auto consoleSink = spdlog::get(Debug::Sink::Console);
        if (consoleSink)
            consoleSink->log(spdLevel, msg);
        else
            std::cout << msg << std::endl;

        auto fileSink = spdlog::get(Debug::Sink::GenericFile);
        if (fileSink)
            fileSink->log(spdLevel, msg);
    }
    else
    {
        auto sink = spdlog::get(sinkName);
        if (sink)
            sink->log(spdLevel, msg);
    }
}

std::mutex Log::sLock;
