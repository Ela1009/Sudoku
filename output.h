#ifndef OUTPUT_H
#define OUTPUT_H

#include "colors.h"
#include <iostream>

class OutputManager {
public:
    static void displayWelcomeMessage();
    static void displayErrorMessage(const std::string& message);
    static void displaySuccessMessage(int num, int row, int col);
    static void displayExitingMessage();
};

#endif // OUTPUTMANAGER_H

