#pragma once

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void clearScreen();
