/* This file contains the main function */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "candidate/candidate.h"
#include "adminisatrative/admin.h"

election elect_name;
int admin_check = 0;

char mainhome_page(void);
void adminhome_page(void);

int main(void)
{
    char code;

    for (; ;) {
        system("clear");
        
        code = mainhome_page();
        switch(code) {
            case 'h':
                system("clear");
                mainhome_page();
                break;
            case 'a':
                admin_check = 0;
                if((admin_check = checkadminlogin()) == 1){
                    system("clear");
                    adminhome_page();
                }
                break;
            default:
                printf("%d not a valid command\n", code);
                break;
        }
    }
    return 0;
}

char mainhome_page(void)
{
    int candidate_number;
    char code;

    printf("\n---------------WELCOME TO OUR HOMEPAGE---------------\n\n");
    printf("h: Homepage\n"
            "a: Admin hompage\n"
            "v: Register vote\n"
            "p: show candidate profile\n");
    
    for(; ;) {
        printf("what do you want to do ?(choose among the operation code above): ");
        scanf("%c", &code);

        while(getchar() != '\n')
            ;
        
        if (code == 'h' || code == 'a')
            return code;
        switch(code) {
            case 2:
                system("clear");
                vote(elect_name);
            case 3:
                system("clear");
                printf("candidate number: ");
                scanf("%d", &candidate_number);
                print_profile(elect_name, candidate_number);
            default:
                printf("%d not a valid operation code\n", code);
        }
    }
     
    return code;
}

void adminhome_page(void)
{
    int candidate_number;
    char code;

    printf("\n------------WELCOME TO THE ADMIN HOMPAGE------------\n");
    printf("e: Start an election\n"
            "c: Create a candidate profile\n"
            "p: View candidate profile\n"
            "d: Delete candidate profile\n"
            "b: Ban a candidate\n"
            "h: Return to main homepage\n"
            "l: Load an election file\n"
            "s: Save current election file\n"
            "n: Change admin name\n"
            "w: Change Password\n"
            "q: quit");

    for(; ;){
        printf("\n\nwhat do you want to do ?(choose among the operatin code above): ");
        scanf("%c", &code);
        while(getchar() != '\n')
            ;
        
        switch(code) {
            case 'e': 
                elect_name = create_election();
                break;
            case 'c':
                make_candidate(elect_name);
                break;
            case 'p':
                printf("Enter candidate number: ");
                scanf("%d", &candidate_number);
                print_profile(elect_name, candidate_number);
                break;
            case 'd':
                delete_candidate(elect_name);
                break;
            case 'b':
                ban_candidate(elect_name);
                break;
            case 'h':
                admin_check = 0;
                return;
                break;
            case 'l':
                laod(elect_name);
                break;
            case 's':
                save(elect_name);
                break;
            case 'n':
                changeadminname();
                break;
            case 'w':
                changeadminpasswd();
                break;
            case 'q':
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("%c code not valid\n", code);
                break;
        }
    }
}
