#include <stdio.h>

void displaySudoku(int myNumbers[], int length){
	printf("__________________\n");
	for(int i = 0; i < length; ++i){
		printf("%d|", myNumbers[i]);
	}
}

int add(int a, int b){
	return a + b;
}
