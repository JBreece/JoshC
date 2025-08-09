#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "generatePuzzle.h"

int main(){
	int *myArray;
	int size;

	printf("What size Sudoku puzzle do you want?");
	scanf("%d", &size);
	while (getchar() != '\n' && getchar() != EOF); // required for scanf, cuts invalid input from end of string
	myArray = generatePuzzle(size);
	displaySudoku(myArray, size);
	free(myArray);
	return 0;
}
