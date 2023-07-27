#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool bord_status[9] = {false};
bool fin[9] = {0};
char square[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkwin(void);
int checkchoice(int Choice);
void board(void);

int main(void)
{
	int player = 1, i, choice, ash;
	bool gol = false;

	char mark;

	do {
		board();
		player = (player % 2) ? 1 : 2;
		printf("%d\n", player);

		printf("player %d enter a square f number: ", player);
		scanf("%d", &choice);

		printf("bo: ");
		for (int i = 0; i < 9; i++)
			printf("%d", bord_status[i]);

		printf("\n"); 
		printf("q: ");
		for (int i = 0; i < 9; i++)
			printf("%c", square[i]);

		if (choice >= 1 || choice <= 9) {

			mark = (player == 1) ? 'X' : 'O';

			ash = checkchoice(choice);

			if ( ash > 0) {
				printf("\nfine play\n");
				square[choice - 1] = mark;
				gol = checkwin();
				
				if (gol) {
					printf("Player %d win", player);
					return 0;
				}
				player++;
			}
			else
				printf("Illegal move\n");
		}
		else
			printf("choice has to be a number bewtween 1-9\n try again\n");
			
	} while (1);
}

int checkchoice(int Choice)
{
	if (bord_status[Choice])
		return -1;

	bord_status[Choice] = true;
	return 1;
}

/*
int checkwin(void)
{
	if (bord_status[0] == bord_status[1] && bord_status[1] == bord_status[2])
		return 1;
	if (bord_status[*/


void board(void)
{
	int i;
	
	for (i = 0; i <= 8; i++) {
		printf("| %c |", square[i]);
		if (( (i + 1) % 3 ) == 0)
			printf("\n");
	}
}

bool checkwin(void)
{
	bool won = false;

	const bool fi[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
 
	for (int i = 0; i < 9; i++) {
		fin[i] = (bord_status[i] & fi[i]);
		printf("%d", fin[i]);
}
	printf("\n");
	
	for (int i = 0; i < 9; i++) {
		if (fin[i] != fi[i])
			return won;
	}

	won = true;
	return won;
}