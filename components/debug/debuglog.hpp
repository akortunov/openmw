#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include <iostream>
#include <sstream>

#include <osg/io_utils>


namespace Debug
{
    enum Level
    {
        Error = 1,
        Warning = 2,
        Info = 3,
        Verbose = 4,
        Marker = Verbose,

        NoLevel = 5 // Do not filter messages in this case
    };

    namespace Sink
    {
        const std::string Console = "console_logger";
        const std::string GenericFile = "file_logger";
        const std::string NavigatorFile = "navigator_logger";
    }

    extern Level CurrentDebugLevel;
}

class Log
{
public:
    // Locks a global lock while the object is alive
    Log(Debug::Level level) :
    mLevel(level),
    mSinkName("")
    {
        mStream = std::stringstream();
    }

    Log(Debug::Level level, const std::string& sinkName) :
    mLevel(level),
    mSinkName(sinkName)
    {
        mStream = std::stringstream();
    }

    // Perfect forwarding wrappers to give the chain of objects to cout
    template<typename T>
    Log& operator<<(T&& rhs)
    {
        mStream << rhs;
        return *this;
    }

    ~Log()
    {
        LogImpl(mStream.str(), mSinkName, mLevel);
    }

private:
    Debug::Level mLevel;
    std::string mSinkName;
    std::stringstream mStream;

    void LogImpl(std::string msg, std::string sinkName, Debug::Level level);
};

#endif
