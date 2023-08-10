/* This file will contain the main function */
#include <stdio.h>
#include "candidate/candidate.h"

int main(void)
{
    election best;

    best = create_election();

    make_candidate(best);

    print_profile(best, 0);
    return 0;
}
