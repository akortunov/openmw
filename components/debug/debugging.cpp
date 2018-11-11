#include "debugging.hpp"

#include <components/crashcatcher/crashcatcher.hpp>

#include <components/files/configurationmanager.hpp>

#include <boost/filesystem/fstream.hpp>
#include <boost/iostreams/stream.hpp>

#include <SDL_messagebox.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Debug
{
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

        switch (CurrentDebugLevel)
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
}

int wrapApplication(int (*innerApplication)(int argc, char *argv[]), int argc, char *argv[], const std::string& appName)
{
    const std::string logName = Misc::StringUtils::lowerCase(appName) + ".log";
    const std::string crashLogName = Misc::StringUtils::lowerCase(appName) + "-crash.log";

    int ret = 0;
    try
    {
        Files::ConfigurationManager cfgMgr;
        auto logFile = cfgMgr.getLogPath() / logName;

        // remove old log file if exists
        if(boost::filesystem::exists(logFile))
            boost::filesystem::remove(logFile);

        // globally register the loggers so so the can be accessed using spdlog::get(logger_name)
        auto console_logger = spdlog::stdout_color_mt(Debug::Sink::Console);
        auto file_logger = spdlog::basic_logger_mt(Debug::Sink::GenericFile, logFile.string());
        console_logger->set_pattern("%^%v%$");
        file_logger->set_pattern("%v");

        // TODO: for now we can not set custom colors
        //console_logger->set_color(spdlog::level::err, "\033[91m"); // red
        //console_logger->set_color(spdlog::level::warn, "\033[93m"); // yellow
        //console_logger->set_color(spdlog::level::info, "\033[m"); // default
        //console_logger->set_color(spdlog::level::debug, "\033[90m"); // dark-gray

        spdlog::level::level_enum level = Debug::GetCurrentDebugLevel();
        console_logger->set_level(level);
        file_logger->set_level(level);

        // install the crash handler as soon as possible. note that the log path
        // does not depend on config being read.
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
