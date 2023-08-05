#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "candidate.h"

struct candidate {
	char *candidate_name;
	char candidate_id[7];
	int num_voates;
	bool banned;
};

struct election_type {
	char election_id[7];
	struct candidate *top;
};

/*functions*/

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC create_election(void)
{
	election el = malloc(sizeof(struct election_type));

	if (el == NULL)
		terminate("\nerror in create: Election could not be started\n");

	el->top = NULL;
	return el;
}
