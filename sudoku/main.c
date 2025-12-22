#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "display.h"
#include "generatePuzzle.h"

int main(){
	int *myArray;
	int size;

	printf("What size Sudoku puzzle do you want to play/solve? (For now, '81' is the only valid answer :))\n");
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

	// user input
	int row, column, number;
	char play[10];
	int *answerArray = malloc(size * sizeof(int));
	printf("Play a game or solve a puzzle? Write \"play\" or \"solve\"\n");
	scanf(" %s", play);
	if(strcmp(play, "play") == 0 || strcmp(play, "Play") == 0 || strcmp(play, "PLAY") == 0){
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
		for (int i = 0; i < size; i++) {
			answerArray[i] = myArray[i];
		}

		// Remove some cells (about 40%–60%)
		int removeCount = size * 0.5; // tweak for difficulty
		for (int k = 0; k < removeCount; k++) {
			int idx = rand() % size;
			myArray[idx] = 0;
		}

		displaySudoku(myArray, size);


		char contPlay = 'y';
		while(contPlay == 'y' || contPlay == 'Y'){
			printf("Enter a number in the format: row,column,number\n");
			scanf("%d,%d,%d", &row, &column, &number);
			myArray[((row - 1) * 9) + column - 1] = number;
			displaySudoku(myArray, size);
			printf("Add/update another number? Y or N\n");
			scanf(" %c", &contPlay);
		}
	}
	else if(strcmp(play, "solve") == 0 || strcmp(play, "Solve") == 0 || strcmp(play, "SOLVE") == 0){
		char inputPuzzle[size];
		printf("Enter your puzzle to solve as a single string of numbers - for example, type \"1234\" and hit enter");
		scanf(" %s", inputPuzzle);
		for(int i = 0; i < size; i++) {
			myArray[i] = inputPuzzle[i];
			answerArray[i] = inputPuzzle[i];
		}
		// TODO do the rest of the solve part
		displaySudoku(myArray, size);
	}
	else{
		printf("Invalid input, try again");
	}

	// answer prompt
	char answer;
	printf("Do you want to check your answer? Y or N\n");
	scanf(" %c", &answer);
	if(answer == 'Y' || answer == 'y')
		displaySudoku(answerArray, size);

	// check answer
	bool correctAnswer = true;
	for(int i = 0; i < size; i++){
		if(myArray[i] != answerArray[i])
			correctAnswer = false;
	}
	if(correctAnswer == true)
		printf("You did it! Nice job solving the puzzle.\n");
	else
		printf("Incorrect! Try playing again with ./runsudoku\n");

	free(myArray);
	free(answerArray);
	return 0;
}
