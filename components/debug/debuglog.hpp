#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include <mutex>
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
    }

    extern Level CurrentDebugLevel;
}

class Log
{
    static std::mutex sLock;

    std::unique_lock<std::mutex> mLock;
public:
    // Locks a global lock while the object is alive
    Log(Debug::Level level) :
    mLock(sLock),
    mLevel(level)
    {
        mStream = std::stringstream();
        // If the app has no logging system enabled, log level is not specified.
        // Show all messages without marker - we just use the plain cout in this case.
        //if (Debug::CurrentDebugLevel == Debug::NoLevel)
        //    return;

        //if (mLevel <= Debug::CurrentDebugLevel)
        //    std::cout << static_cast<unsigned char>(mLevel);
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
        LogImpl(mStream.str(), mLevel);
    }

private:
    Debug::Level mLevel;
    std::stringstream mStream;

    void LogImpl(std::string msg, Debug::Level level);
};

#endif
