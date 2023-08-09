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

PRIVATE struct candidate *search(election el,
					struct candidate *cur_node,
					struct candidate *prev_node,
					int candidate_num)
{
	for(cur_node = el->top, prev_node = NULL;
	 	cur_node != NULL, candidate_num != cur_node->candidate_number;
		prev_node = cur, cur_node = cur->next)
			;

	if(!cur_node)
		printf("Candidate with registration number %d, not found\n", candidate_number);
	
	return cur_node;
}

PUBLIC void print_profile(election el, int candidate_num)
{
	struct candidate *cur, *prev;

	if(!(search(el, cur, prev, candidate_num)))
		return;
	
	printf("\n\
			Canddiate name: %s\n \
			Candidate ID: %s\n\
			Candidate registration number: %d\n\
			number votes: %d\n");

	if (!cur->banned)
		printf("\nStatus: Banned\n");
	else
		printf("\nStatus: Active\n");
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
	 int candidate_number, ch;

	 printf("Enter candidate number: ");
	 scanf("%d", &candidate_number);

	 if(!(search(el, cur, prev, candidate_number)))
	 	return

	printf("\nWARNING!!!: Deleting this candidate\n");

	print_profile(el, candidate_number);

	printf("Continue ? (Y/N)");

	
	if (toupper((ch = getchar())) == 'Y') {
		prev->next = cur->next;
		free(cur);
	}

	else
		printf("Operation Aborted\n");
		
}

PUBLIC void ban_candidate(election el)
{
	struct candidate *p, *prev;
	int candidate_number, ch;

	printf("Enter candidate registration number: ");
	scanf("%d", &candidate_number);

	if(!(search(el, p, prev, candidate_number)));
		return;

	print_profile(el, candidate_number);

	printf("Contitnue ? (Y/N): ");
	
	if((toupper(ch = getchar())) != 'Y') {
		printf("Operation Aborted\n");
		return;
	}

	p->banned = true;
	printf("\nCandidate banned succesfully\n");
}

PUBLIC  void vote(election el)
{
	struct candidate *p, *cur, *prev;
	int candidate_number, ch;

	printf("\nRegistration number\t|\tCandidate name\n");

	for (p = el->top; p != NULL, p = p->next) {
		if (p->banned)
			printf("\n%d.\t|\t%s\n", p->candidate_number, p->candidate_name);
	}

	printf("Enter candidate number to regiser your vote: ");
	scanf("%d", &candidate_number);

	if (!(search(el, cur, prev, candidate_number)))
		return;

	printf("\nRegistering vote for %s\n", cur->candidate_name);
	printf("Register ?(Y/N) ");

	if((toupper(ch = getchar())) 'Y')
		cur->num_voates++;

	else
		printf("Vote not registered\n");
		
}