/* This file will contain the main function */
#include <stdio.h>
#include <stdbool.h>
#include "candidate/candidate.h"
#include "adminisatrative/admin.h"

int main(void)
{
    election best;
    int num;
    char code;

    best = create_election();

    while(!checkadminlogin())
        ;

    changeadminname();
    changeadminpasswd();

    for (; ;) {
        printf("Enter code: ");
        scanf(" %c", &code);

        while(getchar() != '\n')
            ;

        switch(code) {
            case 'a':
                make_candidate(best); break;
            case 'b':
                printf("Enter candidate number: ");
                scanf("%d", &num);
                print_profile(best, num);
                break;
            case 'd': delete_candidate(best);
                    break;   
            case 'n':
                    ban_candidate(best);
                    break;
            case 'v': 
                vote(best);
                break;
            case 'q': return 0;

            default: printf("what!\n");
                break;
        }
    }
    return 0;
}
