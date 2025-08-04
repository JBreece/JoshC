#include <stdio.h>
#include <stdlib.h>
#include "display.h"

int main(){
	int *myArray;
	int size;

	printf("What size Sudoku puzzle do you want?");
	scanf("%d", &size);
	while (getchar() != '\n' && getchar() != EOF);
	if(size == 81){  // TODO make this check for any perfect square, not just 81
		myArray = (int *)malloc(size * sizeof(int));
		if(myArray == NULL){
			printf("Memory allocation failed!\n");
			return 1;
		}
		for(int i = 0; i < size; i++){
			myArray[i] = rand() % 10;
		}
	}
	else{
		printf("Not a valid size!");
		return 1;
	}
	displaySudoku(myArray, size);
	free(myArray);
	return 0;
}
