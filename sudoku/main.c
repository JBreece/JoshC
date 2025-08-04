#include <stdio.h>
#include "display.h"

int main(){
	int sum = add(5, 3);
	printf("Sum: %d\n", sum);
	int myArray[] = {4, 1, 7, 3, 6};
	int length = sizeof(myArray) / sizeof(myArray[0]);
	displaySudoku(myArray, length);
	return 0;
}
