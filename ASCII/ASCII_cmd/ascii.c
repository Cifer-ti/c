//print the ASCII table using a command line program
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *options[] = {"--table", "--val", "--char", "--help"};

int char_to_value(char *str_ch);
int value_to_char(char *val);
void error(char *prog_name);
void help(void);
void table(void);

int main(int argc, char *argv[]) 
{
    int i, arg_index = -1;

    if(argc < 2)
        error(*argv);

    for(i = 0; options[i] != NULL; i++) {
        if(strcmp(argv[1], options[i]) == 0) {
            arg_index = i;
            break;
        }
    }

    if(options[i] == NULL) {
        printf("Error: %s invalid arguements.\n", argv[1]);
        error(*argv);
    }

    if((arg_index == 1 || arg_index == 2) && argc != 3) {
        printf("Error: no arguement to be converted\n");
        error(*argv);
    }

    switch(arg_index) {
        case 0:
            table();
            break;
        
        case 1:
            if(value_to_char(argv[2]) != 0) {
                printf("Error: Arguement to be converted has to be an integer.\n");
                exit(EXIT_FAILURE);
            }
            break;

        case 2:
            char_to_value(argv[2]);
            break;
        
        case 3:
            help();
            break;
        
        default:
            printf("Argument %s not found\n %s --help for help\n", argv[1], *argv);
            return -1;
    }

    return 0;
}

void table(void)
{
    int i;

    for (i = 0; i <= 127; i++) {
        if (i <= 31)
            printf(" |%3d - np|", i);
        else
            printf(" |%3d -  %c|", i, i);
        if (i % 6 == 0)
            printf("\n");
    }
    printf("\n");

}

int char_to_value(char *str_ch) 
{
    char char_ch;

    sscanf(str_ch, "%c", &char_ch);
    printf("character of %c - %d\n", char_ch, char_ch);
}

int value_to_char(char *val) 
{
    int int_val;
    char *endptr;

    strtol(val, &endptr, 10);

    if(*endptr != '\0')
        return -1;
    
    int_val = atoi(val);

    if (int_val >= 0 && int_val <= 31)
        printf("characters with value of 0 - 32 are unprintable\n");
    else if(int_val > 127)
        printf("value should be positive and less than 127\n");
    else
        printf("character of %d - %c\n", int_val, int_val);
    
    return 0;
}

void help(void)
{
    printf("\nhelp page\n"
                "Valid arguements:\n"
                "--table\t print ASCII table\n"
                "--help\t print this help\n");
}

void error(char *prog_name)
{
        printf("Usage: %s --option.\n", prog_name);
        printf("%s --help for more details\n", prog_name);
        exit(EXIT_FAILURE);
}
