#include <stdio.h>

void displaySudoku(int myNumbers[], int length){
	printf("________________________\n");
	if(length == 81){
		for(int i = 0; i < length; ++i){
			if(i != 0 && ((i+1)%27) == 0){
				printf("%d|\n", myNumbers[i]);
				printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
				printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
			}
			else if(i != 0 && ((i+1)%9) == 0){
				printf("%d|\n", myNumbers[i]);
				printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
			}
			else if(i != 0 && ((i+1)%3) == 0){
				printf("%d || ", myNumbers[i]);
			}
			else{
				printf("%d|", myNumbers[i]);
			}
		}
	}else{
	printf("Not a proper sudoku puzzle size!\n");
	}
}
