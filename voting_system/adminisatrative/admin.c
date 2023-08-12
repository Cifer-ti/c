#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "admin.h"
#include "../candidate/candidate.h"

#define NAME_LEN 40
#define PASSWD_LEN 50

struct {
    char name[NAME_LEN + 1];
    char passwd[PASSWD_LEN + 1];
}admin = {"AdmiN", "PassWd"};


PUBLIC int checkadminlogin(void)
{
    char logname[NAME_LEN + 1];
    char logpasswd[PASSWD_LEN + 1];

    printf("Admin name: ");
    read_word(logname, NAME_LEN);

    

    printf("Password: ");
    read_word(logpasswd, PASSWD_LEN);

    if((strcmp(logpasswd, admin.passwd) != 0) && (strcmp(logname, admin.name) != 0)) {
        printf("Wrong Name or Password\n");
        return 0;
    }

    printf("logged in as admin\n");
    return 1;
    
}

PUBLIC void changeadminname(void)
{
    char new_name[NAME_LEN];
    char old_name[NAME_LEN];

    while(1) {
        printf("Enter old name: ");
        read_word(old_name, NAME_LEN);

        if(strcmp(old_name, admin.name) == 0)
            break;
        else
            printf("wrong name!");
    }

    printf("Enter new admin name: ");
    read_word(new_name, NAME_LEN);
    strncpy(admin.name, new_name, NAME_LEN);

    printf("admin name updated successfully\n"); 
}

PUBLIC void changeadminpasswd(void)
{
    char old_passwd[PASSWD_LEN];
    char new_passwd[PASSWD_LEN], conf_passwd[PASSWD_LEN];

    while(1) {
        printf("Enter old password: ");
        read_word(old_passwd, PASSWD_LEN);
        if(strcmp(old_passwd, admin.passwd) == 0)
            break;
        else
            printf("wrong password!\n");
    }

    printf("Enter new password: ");
    read_word(new_passwd, NAME_LEN);
   

    while(1) {
        printf("Confirm new password: ");
        read_word(conf_passwd, NAME_LEN);

        if(strcmp(conf_passwd, new_passwd) == 0) {
            strncpy(admin.name, new_passwd, PASSWD_LEN);
            printf("Password updated succesfully\n");
            return; 
        }
        printf("password not matching\n");
    }

}