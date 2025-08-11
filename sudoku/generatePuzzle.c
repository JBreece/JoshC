#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findEmptyCell(int* arr, int rowSize, int* row, int* col){
	for(int r = 0; r < rowSize; r++){
		for(int c = 0; c < rowSize; c++){
			if(arr[r * rowSize + c] == 0){
				*row = r;
				*col = c;
				return true;
			}
		}
	}
	return false;
}

bool noRulesViolated(int* arr, int rowSize, int digitToTry, int row, int col){
	for(int i = 0; i < rowSize; i++){
		if(arr[row * rowSize + i] == digitToTry)
			return false;
	}
	for(int i = 0; i < rowSize; i++){
		if(arr[i * rowSize + col] == digitToTry)
			return false;
	}
	int boxRowStart = row - row % 3;
	int boxColStart = col - col % 3;
	for (int r = 0; r < 3; r++) {
    		for (int c = 0; c < 3; c++) {
        		if (arr[(boxRowStart + r) * rowSize + (boxColStart + c)] == digitToTry)
            			return false;
    		}
	}
	return true;
}

bool generatePuzzle(int* arr){
	int rowToTry = 0;
	int colToTry = 0;
	if(findEmptyCell(arr, 9, &rowToTry, &colToTry) == false)
		return true;

	int randomNumbers[9];
	for(int i = 0; i < 9; i++){
		randomNumbers[i] = i + 1;
	}
	for(int i = 8; i > 0; i--){
		int j = rand() % (i + 1);
		int temp = randomNumbers[i];
		randomNumbers[i] = randomNumbers[j];
		randomNumbers[j] = temp;
	}

	for(int i = 0; i < 9; i++){
		int currentNumber = randomNumbers[i];
		if(noRulesViolated(arr, 9, currentNumber, rowToTry, colToTry)){
			arr[rowToTry * 9 + colToTry] = currentNumber;
			if(generatePuzzle(arr) == true)
				return true;
		}
	}
	arr[rowToTry * 9 + colToTry] = 0;
	return false;
}

