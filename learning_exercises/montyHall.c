#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	The purpose of this is to demonstrate the Monty Hall problem.
	First, the user is explained the game show situation by the host.
	Then, one of the doors is denoted to be the 'car'.  Simultaneously, all others are denoted to be 'goats'.
	Then, the user chooses a door.
	Then, the host reveals all of the not-chosen goat doors but 1 to the user.
	Then, the user is given the choice to keep their door or switch to the last not-revealed door.
	Answer revealed, game stat recorded.
*/

int main() {
	srand(time(NULL));
	int numPossibleDoors = 3;
	char* possibleDoors = malloc(numPossibleDoors + 1 * sizeof(char)); // 'door numbers' start at 1 for players so this way makes sense
	int correctDoor = 1;
	int hiddenDoor = 2;
	int doorChosen = 1;

	correctDoor = (rand() % numPossibleDoors) + 1;  //TODO put this whole thing in a 'game play' loop

	// welcome
	printf("Welcome to the Monty Hall problem!\n");
	printf("There are 3 doors (by default). Behind one is a car. Behind the other 2 are goats. You pick a door, then I will reveal one of the other 2 doors to show you a goat behind it. Then, you decide whether to swap doors or stick with the one you originally chose. Ready?\n");
	// user input
	printf("How many doors would you like the game to have? The recommended number by default is 3.\n");
	scanf("%d", &numPossibleDoors);
	printf("Perfect. And which door do you think has a car?\n");
	scanf("%d", &doorChosen);
	printf("I will now reveal that these doors ");

	do{
		hiddenDoor = (rand() % numPossibleDoors) + 1;
	} while(hiddenDoor == doorChosen);

	// revealed door determined
	for(int i = 1; i < sizeof(possibleDoors); i++){
		possibleDoors[i] = 'g';
		if(i != correctDoor && i != doorChosen){
			printf(", %d", i);
		}
	}
	possibleDoors[correctDoor] = 'c';
	printf(" all have goats behind them.");
	printf("Knowing this, would you now like to swap doors? Or do you think you have the car and you want to stay? Type 'swap' or 'stay'\n");
	char decision[50];
	scanf("%s", decision);
	if(decision == "swap"){
		int tempDoor = doorChosen;
		doorChosen = hiddenDoor;
		hiddenDoor = tempDoor;
	}
	
	printf("And now to reveal... your chosen door had behind it...!\n A");
	char result = possibleDoors[doorChosen];
	if(result == 'g'){
		printf(" goat!\n");
	}
	else if (result == 'c'){
		printf(" car!\n");
	}
	else{
		printf("n error!\n");
	}

	free(possibleDoors);
	return 0;
}
