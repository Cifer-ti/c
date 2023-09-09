//print the ASCII table using a command line program
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *table[] = {"--table", "--character", "--value", "--help"};
int main(int argc, char *argv[]) {
    int i, j, a;

    if(argc != 2) {
        printf("Usage: %s arguement.\n", *argv);
        printf("%s --help for details\n", *argv);
        exit(EXIT_FAILURE);
    }

    for(i = 0, j = 1; table[i] != NULL; i++) {
        if(strcmp(argv[j], table[i]) == 0) {
            a = i;
            i = j = 0;
            break;
        }
    }

    switch(a) {
        case 0:
            for (i = 0; i <= 127; i++) {
                if (i <= 31)
                    printf(" |%3d - np|", i);
                else
                    printf(" |%3d -  %c|", i, i);
                if (i % 6 == 0)
                printf("\n");
            }
            printf("\n");
            break;
        
        case 1:
            printf("\nhelp page\n"
                "Valid arguements:\n"
                "--table\t print ASCII table\n"
                "--help\t print this help\n");
            break;
        
        default:
            printf("Argument %s not found\n %s --help for help\n", argv[1], *argv);
            return -1;
    }

    return 0;
}
