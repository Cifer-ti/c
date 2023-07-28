#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int bord_status[9] = {0};
bool fin[9] = {0};
char square[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int comp = 0;

int checkwin(void);
int checkchoice(int Choice);
void board(void);

int main(void)
{
	int player = 1, i, choice, ash;
	int gol = 0;

	char mark;

	do {
		board();
		player = (player % 2) ? 1 : 2;
		printf("%d\n", player);

		printf("player %d enter a square f number: ", player);
		scanf("%d", &choice);

		
		if (choice >= 1 || choice <= 9) {

			mark = (player == 1) ? 'X' : 'O';

			ash = checkchoice(choice);

			if ( ash > 0) {
				printf("\nfine play\n");
				square[choice - 1] = mark;
				gol = checkwin();
				
				if (gol > 0) {
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
		
		/*
		printf("bo: ");
		for (int i = 0; i < 9; i++)
			printf("%d", bord_status[i]);

		printf("\n"); 
		printf("q: ");
		for (int i = 0; i < 9; i++)
			printf("%c", square[i]);
		printf("\n");
		*/
			
	} while (1);
}

int checkchoice(int Choice)
{
	if (bord_status[Choice - 1])
		return -1;

	bord_status[Choice - 1] = 1;
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

int checkwin()
{
    if (square[0] == square[1] && square[1] == square[2])
        return 1;
        
    else if (square[3] == square[4] && square[4] == square[5])
        return 1;
        
    else if (square[6] == square[7] && square[7] == square[8])
        return 1;
        
    else if (square[0] == square[3] && square[3] == square[6])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[0] == square[4] && square[4] == square[8])
        return 1;
        
    else if (square[2] == square[4] && square[4] == square[6])
        return 1;
        
    else if (square[0] != '1' && square[1] != '2' && square[2] != '3' &&
        square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] 
        != '7' && square[7] != '8' && square[8] != '9')

        return 0;
    else
        return  - 1;
}
