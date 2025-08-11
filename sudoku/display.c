#include <stdio.h>

void displaySudoku(int myNumbers[], int length){
	printf("__________________\n");
	if(length == 81){
		for(int i = 0; i < length; ++i){
			if(i != 0 && ((i+1)%9) == 0){
				printf("%d|\n", myNumbers[i]);
				printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
			}
			else{
				printf("%d|", myNumbers[i]);
			}
		}
	}else{
	printf("Not a proper sudoku puzzle size!\n");
	}
}
