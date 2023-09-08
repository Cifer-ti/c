#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*defintion of extenal variables*/
int board_status[9] = {0};
char square[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

/*function prototypes*/
void error_prompt(void);
void board(void);
int checkchoice(int Choice);
int checkwin(void);

int main(void)
{
	int player = 1, i, choice, check;
	int has_won = 0;
	char mrk;

	do {
		system("clear");
		board();
		player = (player % 2) ? 1 : 2;

		printf("player %d enter the number of a square: ", player);
		/*check if choice is a number*/
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

/**
 * erro_prompt: Prompts an error message
 */
void error_prompt(void)
{
	printf("\nchoice has to be a number between 1-9\ntry again\n\n");
}

/**
 * board: prints the current state of the game board
 */
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

/**
 * checkchoice: checks if the number the player entered,
 * 		was already entered (checks if the move is legal).
 * 
 * returns an integer value of 1 if the move is legal else,
 * -1 is returned.
 */
int checkchoice(int Choice)
{
	if (board_status[Choice - 1])
		return -1;

	board_status[Choice - 1] = 1;
	return 1;
}

/**
 * checkwin: checks the board to see if the game
 * 	     is a win a draw or should continue.
 *
 * return - 1 if a winning combination is satified,
 * 	    0 if all squares are occupied but no win (a draw)
 *          -1 if non of the above is satisfied
 */
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
