//prints the ASCII table or a particular character
#include <stdio.h>
#include "value.h"
#include "char.h"
#include "table.h"

int main(void) {

    int cmd;

    printf("comands:\n 1- print the full ASCII table\
            \n2- print the ASCII value of a character\
            \n3- print the character of an ASCII value\
            \n0- exit\n");

    for (; ;) {
        printf("\nEnter command: ");
        scanf("%d", &cmd);

        switch (cmd) {
            case 0: 
                return 0;
                break;
            case 1:
                table();
                break;
            case 2:
                value();
                break;
            case 3:
                ch();
                break;
            default:
            printf("command not found\n");
            break;
        }
    }
}