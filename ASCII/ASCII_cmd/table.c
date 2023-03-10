#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *table[] = {"table"};
    int i, j = 0;

    if ((strcmp(argv[1], *table) == 0)) {
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
    else printf("%s: argument not found", argv[1]);
    return -1;
}
