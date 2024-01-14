#include "output.h"
#include "colors.h"
#include <iostream>
#include <windows.h>

void OutputManager::displayWelcomeMessage() {
    std::cout << "Welcome to Sudoku!\n";
    std::cout << "Enter row, column, and number (separated by spaces) to fill a cell.\n";
    std::cout << "For example, '2 3 4' means row 2, column 3, fill with 4.\n";
    std::cout << "Enter '-1' to exit.\n\n";
}

void OutputManager::displayErrorMessage(const std::string& message) {
    setColor(RED_TEXT);
    std::cout << "Error: " << message << "\n";
    resetColor();
}

void OutputManager::displaySuccessMessage(int num, int row, int col) {
    setColor(GREEN_TEXT);
    std::cout << num << " placed at (" << row << ", " << col << ") successfully.\n";
    Beep(1000, 500); 
    resetColor();
}

void OutputManager::displayExitingMessage() {
    std::cout << "Exiting the game. Goodbye!\n";
}
