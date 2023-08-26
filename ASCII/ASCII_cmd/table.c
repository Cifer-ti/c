//print the ASCII table using a command line program
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *table[] = {"--table", "--help"};
    int i, j = 0;

    if(argc != 2) {
        printf("Usage: %s arguement.\n", *argv);
        printf("%s --help for details\n", *argv);
        exit(EXIT_FAILURE);
    }

    if((strcmp(argv[1], *table) == 0)) {
        for (i = 0; i <= 127; i++) {
            if (i <= 31)
                printf(" |%3d - np|", i);
            else
                printf(" |%3d -  %c|", i, i);
            if (i % 6 == 0)
            printf("\n");
        }
        printf("\n");
        return 0;
    }

    if((strcmp(argv[1], table[1]) == 0)) {
        printf("\nhelp page\n"
                "Valid arguements:\n"
                "--table\t print ASCII table\n"
                "--help\t print this help\n");
        return 0;
    }
    else printf("Argument %s not found\n %s --help for help\n", argv[1], *argv);
    return -1;
}
