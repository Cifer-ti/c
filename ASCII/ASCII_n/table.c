#include <stdio.h>
#include "table.h"

void table(void) {
    
    int i;

    for (i = 0; i <= 127; i++) {
        if (i >= 0 && i <= 31) 
            printf(" |%3d - up|", i);
        else
            printf(" |%3d -  %c|", i, i);
        if (i % 6 == 0)
            printf("\n");   
    }
}