#ifndef CANDIDATE_H
#define CANDIDATE_H

typedef sruct election_type *election;

election create_election(void);
void make_candidate(electon elect);
void delete_candidate(election elect);
void ban_candidate(election elect);
void vote(election elect);

#endif
