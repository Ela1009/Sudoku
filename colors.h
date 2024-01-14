#ifndef COLORS_H
#define COLORS_H

#include <windows.h>

enum ConsoleColors {
    BLACK_TEXT = 0,
    RED_TEXT = FOREGROUND_RED,
    GREEN_TEXT = FOREGROUND_GREEN,
};

void setColor(ConsoleColors color);
void resetColor();

#endif // COLORS_H
