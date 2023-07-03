#include <stdio.h>
#include <stdlib.h>

char square[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin(void);
int checkchoice(int Choice);
void board(void);

int main(void)
{
	int player = 1, i, choice, ash;

	char mark;

	do {
		player = (player % 2) ? 1 : 2;

		printf("player %d enter a square number number\n", player);
		scanf("%d", &choice);

		mark = (player == 1) ? 'X' : 'O';

		ash = checkchioce(choice);

		if ( ash > 0)
			square[ash] = mark;
		else
			printf("Illegal move");
			
	}
}

int checkchoice(int Choice)
{

	int i;

	for (i = 0; i < 9; i++) {
		if (square[i] == Choice)
			return (i);
	}

	return -1;
}

int checkwin(void)
{
	if (square[0] == square[1] && square[1] == square[2])
		return 1;
	if (square[
