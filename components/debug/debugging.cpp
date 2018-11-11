#include "debugging.hpp"

#include <components/crashcatcher/crashcatcher.hpp>

#include <components/files/configurationmanager.hpp>

#include <boost/filesystem/fstream.hpp>
#include <boost/iostreams/stream.hpp>

#include <SDL_messagebox.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#ifdef _WIN32
#include <wincon.h>
#endif

namespace Debug
{
    spdlog::level::level_enum MapDebugLevel(Level level)
    {
        switch (level)
        {
            case Error:
                return spdlog::level::err;
            case Warning:
                return spdlog::level::warn;
            case Info:
                return spdlog::level::info;
            default:
                return spdlog::level::debug;
        }
    }

    spdlog::level::level_enum GetCurrentDebugLevel()
    {
        const char* env = getenv("OPENMW_DEBUG_LEVEL");
        if (env)
        {
            std::string value(env);
            if (value == "ERROR")
                CurrentDebugLevel = Error;
            else if (value == "WARNING")
                CurrentDebugLevel = Warning;
            else if (value == "INFO")
                CurrentDebugLevel = Info;
            else if (value == "VERBOSE")
                CurrentDebugLevel = Verbose;
        }
        else
            CurrentDebugLevel = Verbose;

        return MapDebugLevel(CurrentDebugLevel);
    }

    void createFileSink(const std::string& sinkName, const std::string& logName, Level level)
    {
        Files::ConfigurationManager cfgMgr;
        auto filePath = cfgMgr.getLogPath() / logName;
        // remove old log file if exists
        if(boost::filesystem::exists(filePath))
            boost::filesystem::remove(filePath);

        auto logger = spdlog::basic_logger_mt(sinkName, filePath.string());
        logger->set_pattern("%v");
        logger->set_level(MapDebugLevel(level));
    }
}

int wrapApplication(int (*innerApplication)(int argc, char *argv[]), int argc, char *argv[], const std::string& appName)
{
    const std::string logName = Misc::StringUtils::lowerCase(appName) + ".log";
    const std::string crashLogName = Misc::StringUtils::lowerCase(appName) + "-crash.log";

    int ret = 0;
    try
    {
        spdlog::level::level_enum level = Debug::GetCurrentDebugLevel();

        // TODO: find out a more reliable way (especially for windows)
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
#ifdef _WIN32
        console_sink->set_color(spdlog::level::err, RED); // red
        console_sink->set_color(spdlog::level::warn, YELLOW); // yellow
        console_sink->set_color(spdlog::level::info, LIGHTGRAY); // default
        console_sink->set_color(spdlog::level::debug, DARKGRAY); // dark-gray
#else
        console_sink->set_color(spdlog::level::err, "\033[91m"); // red
        console_sink->set_color(spdlog::level::warn, "\033[93m"); // yellow
        console_sink->set_color(spdlog::level::info, "\033[m"); // default
        console_sink->set_color(spdlog::level::debug, "\033[90m"); // dark-gray
#endif
        console_sink->set_pattern("%^%v%$");
        auto console_logger = std::make_shared<spdlog::logger>(Debug::Sink::Console, console_sink);
        console_logger->set_level(level);
        spdlog::register_logger(console_logger);

        Debug::createFileSink(Debug::Sink::GenericFile, logName, Debug::CurrentDebugLevel);

        // install the crash handler as soon as possible. note that the log path
        // does not depend on config being read.
        Files::ConfigurationManager cfgMgr;
        crashCatcherInstall(argc, argv, (cfgMgr.getLogPath() / crashLogName).string());

        ret = innerApplication(argc, argv);
    }
    catch (std::exception& e)
    {
#if (defined(__APPLE__) || defined(__linux) || defined(__unix) || defined(__posix))
        if (!isatty(fileno(stdin)))
#endif
            SDL_ShowSimpleMessageBox(0, (appName + ": Fatal error").c_str(), e.what(), nullptr);

        Log(Debug::Error) << "Error: " << e.what();

        ret = 1;
    }

    return ret;
}
