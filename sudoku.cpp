#include "sudoku.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 9;

bool Sudoku::isSafe(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::solveSudoku() {
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= N; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku()) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

Sudoku::Sudoku() : grid(N, std::vector<int>(N, 0)) {}

void Sudoku::printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                std::cout << " ";
            }
            std::cout << grid[i][j] << " ";
        }
        if ((i + 1) % 3 == 0 && i != 8) {
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Sudoku::generateSudoku() {
    solveSudoku();

    srand(static_cast<unsigned int>(time(0)));
    int toRemove = N * N / 2;

    while (toRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            toRemove--;
        }
    }
}

bool Sudoku::fillCell(int row, int col, int num) {
    if (row < 0 || row >= N || col < 0 || col >= N || num < 1 || num > 9) {
        throw std::invalid_argument("Invalid input! Row, column, or number is out of range.");
    }

    if (grid[row][col] != 0 || !isSafe(row, col, num)) {
        throw std::runtime_error("Invalid move! The cell is already filled or the number is not allowed.");
    }

    grid[row][col] = num;
    return true;
}


std::vector<std::vector<int>>& Sudoku::getGrid() {
    return grid;
}
