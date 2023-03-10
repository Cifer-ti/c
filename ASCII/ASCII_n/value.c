#include <stdio.h>
#include "value.h"

void value(void) {
    char ch;

    printf("Enter charater to get ASCII value: ");
    scanf(" %c", &ch);

    printf("character of %c - %d\n", ch, ch);
}