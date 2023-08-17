/* This file contains the main function */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "candidate/candidate.h"
#include "adminisatrative/admin.h"

void home_page(void);

int main(void)
{
    int code = 0;

    switch(code) {
        case 0:
            mainhome_page();
            break;

            
    }

}

void mainhome_page(void)
{
    printf("\n------WELCOME TO OUR HOMEPAGE--------\n");
    printf("what do you want to do (choose among the options below):\n");
    printf("0: Homepage\n"
            "1: Login as administrator\n"
            "2: show candidate profile\n");
}
