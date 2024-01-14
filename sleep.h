#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void mySleep(int milliseconds);
