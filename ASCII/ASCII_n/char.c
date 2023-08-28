/* Prints a character from the ASCII table  
*  when given it's corresponding number*/
#include <stdio.h>
#include "char.h"

void ch(void) {
    int value;

    printf("Enter value to get ASCII character: ");
    scanf("%d", &value);

    if (value >= 0 && value <= 31)
        printf("characters with value of 0 - 32 are unprintable");
    else
        printf("character of %d - %c\n", value, value);
}