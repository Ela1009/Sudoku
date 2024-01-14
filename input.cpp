#include "input.h"
#include <iostream>

void InputManager::getCoordinatesAndNumber(int& row, int& col, int& num) {
    std::cout << "\nEnter row, column, and number: ";
    std::cin >> row;

    if (row == -1) {
        return;
    }

    std::cin >> col >> num;
}
