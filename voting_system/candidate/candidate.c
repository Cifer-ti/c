/*in here are functions that manage candidate and election operations*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "candidate.h"

#define NAME_LEN 20

int num_candidates = 0;

struct candidate {
	char candidate_name[NAME_LEN];
	int candidate_number;
	int num_voates;
	bool banned;
	struct candidate *next;
};

struct election_type {
	char election_name[NAME_LEN];
	int election_status; /*1 if opened, 0 if closed*/
	int num_candiates;
	struct candidate *top;
};

/*functions defintion*/

/**
 * terminat: Prints a message to the error stream,
 * 			 before terminating the program abroptely.
 * 
 * message- the message to be printed
 */
PRIVATE void terminate(const char *message)
{
	fprintf(stderr, "\n%s\n", message);
	exit(EXIT_FAILURE);
}

/**
 * search: searches for a candidate node, having a candidate
 * 			number described by it's 4th arguement, and makes
 * 			it's 2nd and 3rd arguement point to the the searched node
 * 			and previous node respectively.
 * 
 * el- a pointer to the head of the list.
 * *cur_node- A pointer to a pointer which points to the searched node.
 * *prev_node- A pointer to a pointer which points to the node previous
 * 				to the searched node.
 * candidate_num- The candidate number of the searched candidate node.
 * 
 * return- Returns a NULL pointer if the node isn't found.
*/
PRIVATE struct candidate *search(election el,
					struct candidate **cur_node,
					struct candidate **prev_node,
					int candidate_num)
{
	for(*cur_node = el->top, *prev_node = NULL;
	 	*cur_node != NULL && candidate_num != (*cur_node)->candidate_number;
		*prev_node = *cur_node, *cur_node = (*cur_node)->next)
			;

	if(!*cur_node) {
		printf("Candidate with registration number %d, not found\n", candidate_num);
		return NULL;
	}

}

/**
 * num_cand: checks for the number of nodes currently in the list
 * 
 * el- A pointer to the haed of the list
 * 
 * return- Returns the number of nodes found.
*/
PRIVATE int num_cand(election el)
{
	int i = 0;
	struct candidate *p;

	for (p = el->top; p != NULL; p = p->next)
		i++;

	return i;	
}

PUBLIC int read_word(char word[], int len)
{
	int pos = 0;
	char ch;

	while (((ch = getchar()) != '\n') && ch != EOF) {
		if (pos < len)
			word[pos++] = ch; 
	}
	word[pos] = '\0';
	return pos;
}

PUBLIC void print_profile(election el, int candidate_num)
{

	if(el->top == NULL) {
		printf("\nThere is no candidate registered for tis election yet\n");
		return;
	}
	
	struct candidate *cur, *prev;

	if(!((search(el, &cur, &prev, candidate_num))))
		return;
	
	printf("\n"
			"Canddiate name: %s\n"
			"Candidate registration number: %d\n"
			"number votes: %d\n", cur->candidate_name, 
								cur->candidate_number, cur->num_voates);

	if (cur->banned)
		printf("\nStatus: Banned\n");
	else
		printf("\nStatus: Active\n");
}

PUBLIC election create_election(void)
{
	election el = malloc(sizeof(struct election_type));

	if (el == NULL)
		terminate("Error in create: Election could not be started");

	el->top = NULL;

	printf("Enter a name for the election: ");
	read_word(el->election_name, NAME_LEN);

	el->election_status = opened;

	return el;
}


PUBLIC void make_candidate(election el)
{
	struct candidate *new_node = malloc(sizeof(struct candidate));
	static int candidate_num_gen = 0;

	if (new_node == NULL)
		terminate("Error in create: Candidate could not be created");

	printf("Enter Candidate name: ");
	read_word(new_node->candidate_name, NAME_LEN);

	new_node->candidate_number = ++candidate_num_gen;
	new_node->num_voates = 0;
	new_node->banned = false;
	new_node->next = el->top;
	el->top = new_node;
}


PUBLIC void delete_candidate(election el)
{
	if(el->top == NULL) {
		printf("\nThere is no candidate registered for tis election yet\n");
		return;
	}

	if(el->election_status == closed) {
		printf("This election has already been closed\n");
		return;
	}

	 struct candidate *cur;
	 struct candidate *prev;
	 int candidate_number, ch;

	 printf("Enter candidate number: ");
	 scanf("%d", &candidate_number);
	 getchar();

	 if(!(search(el,  &cur, &prev, candidate_number)))
	 	return;

	printf("\nWARNING!!!: Deleting this candidate\n");

	print_profile(el, candidate_number);

	printf("Continue ? (Y/N)");

	
	if (toupper((ch = getchar())) == 'Y') {
		prev->next = cur->next;
		free(cur);
		printf("Candidate deleted successfully\n");
	}

	else
		printf("Operation Aborted\n");
		
}


PUBLIC void ban_candidate(election el)
{
	if(el->top == NULL) {
		printf("\nThere is no candidate registered for tis election yet\n");
		return;
	}

	if(el->election_status == closed) {
		printf("This election has already been closed\n");
		return;
	}

	struct candidate *p, *prev;
	int candidate_number, ch;

	printf("Enter candidate registration number: ");
	scanf("%d", &candidate_number);
	getchar();

	if(!(search(el, &p, &prev, candidate_number)))
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
	if(el->top == NULL) {
		printf("\nThere is no candidate registered for this election yet\n");
		return;
	}

	if(el->election_status == closed) {
		printf("This election has already been closed\n");
		return;
	}
	
	struct candidate *p, *cur, *prev;
	int candidate_number, ch;

	printf("\nRegistration number\t|\tCandidate name\n");
	for (p = el->top; p != NULL; p = p->next) {
		if (!p->banned)
			printf("\n%d.\t|\t%s\n", p->candidate_number, p->candidate_name);
	}

	printf("Enter candidate number to regiser your vote: ");
	scanf("%d", &candidate_number);
	getchar();

	if (!(search(el, &cur, &prev, candidate_number)))
		return;
	
	if(cur->banned) {
		printf("\nThis candidate has been banned\n");
		return;
	}

	printf("\nRegistering vote for %s\n", cur->candidate_name);
	printf("Register ?(Y/N) ");

	if((toupper(ch = getchar())) ==  'Y') {
		cur->num_voates++;
		printf("Vote registered for %s\n", cur->candidate_name);
	}

	else
		printf("Vote not registered\n");
		
}

PUBLIC void showelection_profile(election el)
{
	el->num_candiates = num_cand(el);
	
	printf("\nelection name: %s\n"
			"number of candidates registered: %d\n",
					el->election_name, el->num_candiates);
	
	if(el->election_status)
		printf("Election status: Opened\n");
	else
		printf("election status: Closed");
}

PUBLIC void close_election(election el)
{
	char ch;

	printf("Are you sure you want to close this election ? (Y/N): ");
	ch = getchar();
	while(getchar() != '\n')
		;
	
	if((toupper(ch)) == 'Y') {
		el->election_status = closed;
		printf("Election closed\n");
		return;
	}
	printf("operation aborted\n");
}

PUBLIC void save(election el)
{
	FILE *fp;
	char filename[300];

	printf("Enter name of file to save: ");
	read_word(filename, 300);

	num_candidates = num_cand(el);

	if((fp = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "Error: election data can't be written to %s file", filename);
		return;
	}

	fwrite(el->top, sizeof(struct candidate), num_candidates, fp);
	fclose(fp);		
}

PUBLIC void laod(election el)
{
	FILE *fp;
	char filename[300];

	printf("Enter name of election file to load it: ");
	read_word(filename, 300);

	if((fp = fopen(filename, "rb")) == NULL) {
		fprintf(stderr, "Error: can't open file %s\n", filename);
		return;
	}

	fread(el, sizeof(struct candidate), 300, fp);
	fclose(fp);
}