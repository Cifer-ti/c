#ifndef CANDIDATE_H
#define CANDIDATE_H

/*tells if a function is to be used out of file or not*/
#define PUBLIC
#define PRIVATE static

typedef struct election_type *election;

PUBLIC create_election(void);
PUBLIC void make_candidate(electon elect);
PUBLIC void delete_candidate(election elect);
PUBLIC void ban_candidate(election elect);
PUBLIC void vote(election elect);

#endif
