#include "colors.h"

void setColor(ConsoleColors color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

