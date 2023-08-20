#ifndef CANDIDATE_H
#define CANDIDATE_H

/*tells if a function is to be used out of file or not*/
#define PUBLIC
#define PRIVATE static
#define opened 1
#define closed 0

typedef struct election_type *election;

/*create_election: */
PUBLIC election create_election(void);

/*make_candidate: creates a new candidate profile*/
PUBLIC void make_candidate(election el);

/*delete_candidate: deletes a candididate profile*/
PUBLIC void delete_candidate(election el);

/*ban_candidate: bans a candidate*/
PUBLIC void ban_candidate(election el);

/*vote: Adds vote to a candidate*/
PUBLIC void vote(election el);

/*close election: closes an ongoing election*/
PUBLIC void close_election(election el);

/*showelection_profile: prints out the the name of an election,
                        the number of candidates registered,
                        and it's status*/
PUBLIC void showelection_profile(election el);

/*print_profile: prints out information of a candidate*/
PUBLIC void print_profile(election el, int candidate_num);

/*read_word: reads a sentence, into the string specified by it's first arguement
 word: the string into which what is read is stored
 len: the max amount of words that can be read into the strin
 return: returns the number of characters read into the string*/
PUBLIC int read_word(char word[], int len);

/*save: saves electoin data into a file (not yet operational)*/
PUBLIC void save(election el);

/*load: loads election data from a file (not yet operational)*/
PUBLIC void laod(election el);

#endif