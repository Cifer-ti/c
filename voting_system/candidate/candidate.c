#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "candidate.h"

#define ID_LEN 7
#define NAME_LEN 20

struct candidate {
	char candidate_name[NAME_LEN];
	char candidate_id[ID_LEN];
	int candidate_number;
	int num_voates;
	bool banned;
	struct candidate *next;
};

struct election_type {
	char election_id[ID_LEN];
	struct candidate *top;
};

/*functions*/

PRIVATE void terminate(const char *message)
{
	printf("\n%s\n", message);
	exit(EXIT_FAILURE);
}

PRIVATE int read_word(char *word, int len)
{
	int pos = 0;
	char ch;

	while ((ch = getchar()) != '\n') {
		if (pos < len)
			word[pos++] = ch; 
	}
	return pos;
}

PUBLIC create_election(void)
{
	election el = malloc(sizeof(struct election_type));

	if (el == NULL)
		terminate("Error in create: Election could not be started");

	el->top = NULL;

	printf("You need an election ID to continue\n"
			"Enter an election ID: ");
	read_word(el->election_id, ID_LEN);
	return el;
}

PUBLIC void make_candidate(election el)
{
	struct candidate *new_node = malloc(sizeof(struct candidate));

	if (new_node == NULL)
		terminate("Error in create: Candidate could not be created");
	
	printf("Candidate needs an ID number\n"
			"Enter candidate ID number: ");
	read_word(new_node->candidate_id, ID_LEN);

	printf("Enter Candidate name: ");
	read_word(new_node->candidate_name, NAME_LEN);

	new_node->num_voates = 0;
	new_node->banned = false;

	new_node->next = el->top;
	el->top = new_node;
}

PUBLIC void delete_candidate(election el)
{
	 struct candidate *cur, *prev;
	 int candidate_number;

	 printf("Enter candidate number: ");
	 scanf("%d", &candidate_number);

	 for(cur = el->top, prev = NULL;
	 	cur != NULL, candidate_number != cur->candidate_number;
		prev = cur, cur = cur->next)
			;
	
	if(!cur) {
		printf("\ncandidate number %d, not found\n", candidate_number);
		return;
	}

	printf("\nWARNING!!!: Deleting this candidate\n")
	/* function to print candidate profile here*/

	printf("Continue ? (Y/N)");

	
	if (toupper((ch = getchar())) == 'Y') {
		prev->next = cur->next;
		free(cur);
	}

	else
		printf("Operation Aborted\n");
		
}