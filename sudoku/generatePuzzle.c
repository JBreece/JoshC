#include <stdio.h>
#include <stdlib.h>

int* generatePuzzle(int size){
	int *myArray;
	if(size == 81){ // TODO make this check for any perfect square, not just 81
		myArray = (int *)malloc(size * sizeof(int));
		if(myArray == NULL){
			printf("Memory allocation failed!\n");
			return NULL;
		}
		for(int i = 0; i < size; i++){
			myArray[i] = rand() % 10;
		}
	}
	else{
		printf("Not a valid size!");
		return NULL;
	}
	return myArray;
}
