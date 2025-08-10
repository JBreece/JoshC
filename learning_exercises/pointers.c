#include <stdio.h>

void setToZero(int arr[], int size){
	int* ptr = arr;
	for(int i = 0; i < (size/sizeof(int)); i++){
		*ptr = 0;
		ptr++;
	}
	return;
}

void printChars(char* str){
	char* ptr = str;
	while(*ptr != '\0'){
		printf("%c\n", *ptr);
		ptr++;
	}
	return;
}

void countVowels(char* str){
	char* ptr = str;
	int numVowels = 0;
	while(*ptr != '\0'){
		if(*ptr=='a'||*ptr=='e'||*ptr=='i'||*ptr=='o'||*ptr=='u'||
		*ptr=='A'||*ptr=='E'||*ptr=='I'||*ptr=='O'||*ptr=='U'){
			numVowels++;
		}
		ptr++;
	}
	printf("Number of vowels is %d\n", numVowels);
	return;
}

int main(){
	// challenge A - set to zero, no arr[i]
	int myArr[] = {5, 3, 6, 8};
	setToZero(myArr, sizeof(myArr));
	for(int i = 0; i < (sizeof(myArr)/sizeof(int)); i++)
		printf("%d\n", myArr[i]);

	// challenge B - print string, no arr[i]
	char* myStr = "test";
	printChars(myStr);

	// challenge C - count vowels, no arr[i]
	char* myStr2 = "testWIthVowEls";
	countVowels(myStr2);

	// return
	return 0;
}
