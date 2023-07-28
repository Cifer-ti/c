#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/*defintion of extenal variables*/
int bord_status[9] = {0};
char square[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

/*function prototypes*/
int checkwin(void);
int checkchoice(int Choice);
void board(void);
void error_prompt(void);

int main(void)
{
	int player = 1, i, choice, check;
	int has_won = 0;
	char mark;

	do {
		board();
		player = (player % 2) ? 1 : 2;

		printf("player %d enter the number of a square: ", player);
		if (scanf("%d", &choice) != 1) {
			getchar();
			choice = -1;
		}

		
		if (choice >= 1 && choice <= 9) {

			mark = (player == 1) ? 'X' : 'O';

			check = checkchoice(choice);

			if ( check > 0) {
				printf("\nfine play\n");
				square[choice - 1] = mark;
				has_won = checkwin();
				
				if (has_won == 0) {
					board();
					printf("Draw game: No more empty square left\n");
					return 0;
				}
				if (has_won > 0) {
					board();
					printf("Player %d win\n", player);
					return 0;
				}
				player++;
			}
			else
				printf("Illegal move\n");
		}
		else
			error_prompt();	
	} while (1);
}

int checkchoice(int Choice)
{
	if (bord_status[Choice - 1])
		return -1;

	bord_status[Choice - 1] = 1;
	return 1;
}


void error_prompt(void)
{
	printf("\nchoice has to be a number between 1-9\ntry again\n\n");
}

void board(void)
{
	int i;
	
	printf("\n");
	for (i = 0; i <= 8; i++) {
		printf("| %c |", square[i]);
		if (( (i + 1) % 3 ) == 0)
			printf("\n");
	}
	printf("\n");
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
