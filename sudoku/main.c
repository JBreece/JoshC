#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "generatePuzzle.h"

int main(){
	int *myArray;
	int size;

	printf("What size Sudoku puzzle do you want?");
	scanf("%d", &size);
	while (getchar() != '\n' && getchar() != EOF); // required for scanf, cuts invalid input from end of string

	if(size == 81){ // TODO make this check for any perfect square, not jus>
        	myArray = (int *)malloc(size * sizeof(int));
        	if(myArray == NULL){
			printf("Memory allocation failed!\n");
                        return 1;
		}
        }
        else{
                printf("Not a valid size!");
                return 1;
        }

	// sets default value to 0 for checking if empty in generatePuzzle()
	// TODO update this to calloc
	if(myArray == NULL)
		return 1;
	else{
		for(int i = 0; i < size; i++){
			myArray[i] = 0;
		}
	}

    srand(time(NULL));
	generatePuzzle(myArray);
	displaySudoku(myArray, size);
	free(myArray);
	return 0;
}
