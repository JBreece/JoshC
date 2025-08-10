#include <stdio.h>
#define ROWS 3
#define COLS 4

void countdown(int n){
	if(n <= 0){
		printf("Done!\n");
		return;
	}
	else{
		printf("%d\n", n);
		countdown(n - 1);
	}
}

int sumArray(int arr[], int size){
	if(size == 0)
		return 0;
	else
		return arr[size-1] + sumArray(arr, size - 1);
}

void reversePrint(char str[]){
	if(str[0] == '\0')
		return;
	else{
		reversePrint(str + 1);
	}
	printf("%c", str[0]);
}

int findExit(char maze[3][4], int row, int col){
	if(row < 0 || col < 0 || row >= ROWS || col >= COLS)
		return 0;
	else if(maze[row][col] == 'E')
		return 1;
	else if(maze[row][col] == '#' || maze[row][col] == 'V'){
		return 0;
	}

	maze[row][col] = 'V';

	if(findExit(maze, row + 1, col)) return 1;
	if(findExit(maze, row - 1, col)) return 1;
	if(findExit(maze, row, col + 1)) return 1;
	if(findExit(maze, row, col - 1)) return 1;

	return 0;
}

int main(){
	// intro
	printf("Hello World!\n");

	// challenge 1 - countdown
	int i = 3;
	countdown(i);

	// challenge 2 - sum of array
	int nums[] = {2, 4, 6};
	int sum = sumArray(nums, 3);
	printf("sum is %d\n", sum);

	// challenge 3 - reverse string
	reversePrint("cat");
	printf("\n");

	// challenge 4 - find path in a maze
	char maze[3][4] = {
		{'.', '.', '#', 'E'},
		{'#', '.', '#', '.'},
		{'.', '.', '.', '.'}
	};
	printf("%d\n", findExit(maze, 0, 0));

	// exit
	return 0;
}


