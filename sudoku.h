#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

class Sudoku {
private:
    std::vector<std::vector<int>> grid;

    bool isSafe(int row, int col, int num);
    bool solveSudoku();

public:
    Sudoku();
    void printGrid();
    void generateSudoku();
    bool fillCell(int row, int col, int num);
    std::vector<std::vector<int>>& getGrid();
};

#endif /* SUDOKU_H */
