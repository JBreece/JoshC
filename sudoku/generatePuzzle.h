#ifndef GENERATE_PUZZLE_H
#define GENERATE_PUZZLE_H
#include <stdbool.h>

bool generatePuzzle(int* arr);
bool findEmptyCell(int* arr, int rowSize, int* row, int* col);
bool noRulesViolated(int* arr, int rowSize, int digitToTry, int row, int col);

#endif
