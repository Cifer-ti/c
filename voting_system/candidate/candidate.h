#ifndef CANDIDATE_H
#define CANDIDATE_H

/*tells if a function is to be used out of file or not*/
#define PUBLIC
#define PRIVATE static

typedef struct election_type *election;

PUBLIC election create_election(void);
PUBLIC void make_candidate(election el);
PUBLIC void delete_candidate(election el);

PUBLIC void ban_candidate(election el);
PUBLIC void vote(election el);

PUBLIC void print_profile(election el, int candidate_num);
#endif