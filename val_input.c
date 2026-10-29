
#include <stdio.h>
#include "apc.h"

int validate_input(char *argv[])
{
    int i;

    /* First number */
    i = 0;

    if (argv[1][0] == '-')
    {
        i = 1;
    }

    if (argv[1][i] == '\0')
    {
        printf("ERROR: First number is empty\n");
        return FAILURE;
    }

    for (; argv[1][i] != '\0'; i++)
    {
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            printf("ERROR: First number invalid operand: %c\n", argv[1][i]);
            //printf("--------------------------------------------------\n");
            return FAILURE;
        }
    }

    /* Operator */
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/')
    {
        printf("ERROR:  invalid operator: %c\n", argv[2][0]);
       // printf("--------------------------------------------------\n");
        return FAILURE;
    }

    /* Second number */
    i = 0;

    if (argv[3][0] == '-')
    {
        i = 1;
    }

    if (argv[3][i] == '\0')
    {
        printf("ERROR: Second number is empty\n");
        return FAILURE;
    }

    for (; argv[3][i] != '\0'; i++)
    {
        if (!(argv[3][i] >= '0' && argv[3][i] <= '9'))
        {
            printf("ERROR: Second number invalid: %c\n", argv[3][i]);
            return FAILURE;
        }
    }

    return SUCCESS;
}
