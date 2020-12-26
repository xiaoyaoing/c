#include <stdio.h>

int space = 0, barrier = 1, box = 2, goal = 3, man = 4, goalDone = 5, manAtGoal = 7;
char input;
int i, j, row, column;
int boxLeft = 1;
int restart = 0;
int level = 0, steps = 0, retry = 0;

int currMap[12][12];

int map1[12][12] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 0, 1, 2, 0, 1, 0},
	{0, 0, 1, 0, 3, 0, 3, 1, 4, 0, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int map2[12][12] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
	{1, 3, 3, 1, 2, 2, 0, 1, 0, 0, 0, 0},
	{1, 0, 3, 3, 2, 0, 0, 1, 1, 1, 1, 1},
	{1, 0, 4, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 3, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int map3[12][12] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1},
	{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 4, 2, 0, 1, 0, 0, 1},
	{0, 1, 1, 1, 0, 2, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0, 1, 3, 3, 0, 0, 1},
	{0, 0, 1, 1, 0, 1, 1, 3, 1, 0, 1, 1},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
};

void intro() {
	printf("****************************************\n");
	printf("\n\n\n\n\n");
	printf("      Game Rules:\n");
	printf("      * Manipulate the little man ♂\n");
	printf("      * through the arrow keys ↑↓←→\n");
	printf("      * to push all the boxes     ■\n");
	printf("      * to the destination        ◇\n");
	printf("      * The little man could not move\n        in front of the obstacle  █\n");
	printf("      * You can enter 'R' to restart\n        the current level\n");
	printf("\n\n\n\n");
	printf("****************************************\n");
	printf("        Press Enter to start\n");

}

//Load a map to currMap.
void loadMap(int map[12][12]){
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			currMap[i][j] = map[i][j];
		}
	}
}

//Record the row and column of the man.
void findMan() {
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			if (currMap[i][j] == man || currMap[i][j] == manAtGoal) {
				row = i, column = j;
				break;
			}
		}
	}
}

//Receive the map name and print the map.
void printMap(int map[12][12]) {
	printf("****************************************\n");
	printf("Level :%d       Steps :%d       Retry :%d\n\n\n", level, steps, retry);
	for (i = 0; i < 12; i++) {

		printf("      ");

		for (j = 0; j < 12; j++) {
			switch (map[i][j]) {
				case 0:
					printf("  ");
					break;
				case 1:
					printf("█");
					break;
				case 2:
					printf("■");
					break;
				case 3:
					printf("◇");
					break;
				case 4:
					printf("♂");
					break;
				case 5:
					printf("◆");
					break;
				case 7:
					printf("♀");
					break;
			}
		}
		printf("      \n");
	}
	printf("\n\n          Enter 'R' to restart\n");
	printf("****************************************");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

//Receive the keyboard input and implement changes to the array currMap.
void move(char input) {
	findMan();
	int A = 0, B = 0; //row and column number
	switch (input) {
	case 72://up
		A = -1, B = 0;
		break;
	case 75://left
		A = 0, B = -1;
		break;
	case 80://down
		A = 1, B = 0;
		break;
	case 77://right
		A = 0, B = 1;
		break;
	}
		
	if (currMap[row + A][column + B] == space || currMap[row + A][column + B] == goal) {
		currMap[row + A][column + B] += 4;//space -> man or goal -> man at goal
		currMap[row][column] -= 4;//man -> space
		steps += 1;
	}

	if (currMap[row + A][column + B] == box || currMap[row + A][column + B] == goalDone) {
		if (currMap[row + 2 * A][column + 2 * B] == space || currMap[row + 2 * A][column + 2 * B] == goal) {
			currMap[row + 2 * A][column + 2 * B] += 2;//space -> box or goal -> goal done
			currMap[row + A][column + B] += 2;//box -> man or goalDone -> man at goal
			currMap[row][column] -= 4;//man -> space or man at goal -> goal
			steps += 1;
		}
	}
}	

//Check the number of boxLeft.
void isOver(){
	boxLeft = 0;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			if (currMap[i][j] == 2)
				boxLeft += 1;
		}
	}
}

void play(int map[12][12]) {
	steps = 0;
	restart = 0;
	loadMap(map);
	isOver();
	printMap(currMap);
	while (boxLeft > 0) {
		input = getch();
		if (input == 82) {
			restart = 1;
			retry += 1;
			break;
		}
		if (input == 72 || input == 75 || input == 77 || input == 80 ) {
			move(input);
			printMap(currMap);
			isOver();
		}
	}
}

int main() {

	intro();

	while(getchar() == '\n')
		break;

	level = 1;
	retry = 0;
	play(map1);
	while (restart == 1) {
		play(map1);
	}

	printf("You have passed level 1.\nPress Enter to continue.\n");
	while (getchar() == '\n')
		break;

	level = 2;
	retry = 0;
	play(map2);
	while (restart == 1) {
		play(map2);

	}

	printf("You have passed level 2.\nPress Enter to continue.\n");
	while (getchar() == '\n')
		break;

	level = 3;
	retry = 0;
	play(map3);
	while (restart == 1) {
		play(map3);
	}
	printf("Congratulations! You have passed all 3 levels!");
}