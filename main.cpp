#include "sudoku.h"
#include "output.h"
#include "input.h"
#include "clear.h"
#include "sleep.h"
#include <iostream>
#include <stdexcept>

int main() {
    Sudoku game;
    game.generateSudoku();

    OutputManager::displayWelcomeMessage();
    mySleep(10000);  

    while (true) {
        clearScreen();  

        game.printGrid();

        int row, col, num;
        InputManager::getCoordinatesAndNumber(row, col, num);

        if (row == -1) {
            OutputManager::displayExitingMessage();
            break;
        }

        try {
            if (!game.fillCell(row - 1, col - 1, num)) {
                OutputManager::displayErrorMessage("Invalid move! Try again.");
            }
            else {
                OutputManager::displaySuccessMessage(num, row, col);
                mySleep(2000);  
            }
        }
        catch (const std::invalid_argument& e) {
            OutputManager::displayErrorMessage("Invalid input: " + std::string(e.what()));
            mySleep(2000);
        }
        catch (const std::runtime_error& e) {
            OutputManager::displayErrorMessage("Runtime error: " + std::string(e.what()));
            mySleep(2000);
        }
    }

    return 0;
}
