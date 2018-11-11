#ifndef DEBUG_DEBUGGING_H
#define DEBUG_DEBUGGING_H

#include "debuglog.hpp"

int wrapApplication(int (*innerApplication)(int argc, char *argv[]), int argc, char *argv[], const std::string& appName);

#endif
