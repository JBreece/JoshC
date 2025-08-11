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
	// Copy solved puzzle into answer key
	int *answerArray = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		answerArray[i] = myArray[i];
	}

	// Remove some cells (about 40%–60%)
	int removeCount = size * 0.4; // tweak for difficulty
	for (int k = 0; k < removeCount; k++) {
		int idx = rand() % size;
		myArray[idx] = 0;
	}

	displaySudoku(myArray, size);

	char answer;
	printf("Do you want to check your answer? Y or N\n");
	scanf("%c", &answer);
	if(answer == 'Y' || answer == 'y')
		displaySudoku(answerArray, size);

	free(myArray);
	free(answerArray);
	return 0;
}
