#include "apc.h"
#include<stdio.h>
int main(int argc, char *argv[])
{
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *res_head = NULL;
    Dlist *res_tail = NULL;

    char op;
    char sign1 = '+';
    char sign2 = '+';

    char *num1;
    char *num2;

    int cmp;
    printf("--------------------------------------------------\n");
    if(validate_number_of_CLA(argc)==FAILURE)
    {
        printf("ERROR: Invalid number of command line arguments\n");
        printf("--------------------------------------------------\n");
        printf("addition        : ./a.out operand1 + operand2\n");
        printf("subtraction     : ./a.out operand1 - operand2\n");
        printf("multiplication  : ./a.out operand1 * operand2\n");
        printf("division        : ./a.out operand1 / operand2\n");
        printf("--------------------------------------------------\n");
        return FAILURE;
    }

    if(validate_input(argv)==FAILURE)
    {
        //printf("ERROR: Invalid input\n");
        printf("--------------------------------------------------\n");
        return FAILURE;
    }

    op = argv[2][0];

    //Checking sign of number 1
     
    if (argv[1][0] == '-')
    {
        sign1 = '-';
        num1 = argv[1] + 1;
    }
    else
    {
        num1 = argv[1];
    }
    //Checking sign of number 2
    if (argv[3][0] == '-')
    {
        sign2 = '-';
        num2 = argv[3] + 1;
    }
    else
    {
        num2 = argv[3];
    }
    slicing_input_dll(num1, &head1, &tail1);
    slicing_input_dll(num2, &head2, &tail2);

    cmp = compare(head1, head2);
    //ADDITION
    if (op == '+')
    {
        if (sign1 == '+' && sign2 == '+')
        {
            addition(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
            printf("Result: ");
        }
        else if (sign1 == '-' && sign2 == '-')
        {
            addition(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
            printf("Result: -");
        }
        else if (sign1 == '-' && sign2 == '+')
        {
            if (cmp > 0)
            {
                subtraction(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
                printf("Result: -");
            }
            else
            {
                subtraction(&head2, &tail2, &head1, &tail1, &res_head, &res_tail);
                printf("Result: ");
            }
        }
        else
        {
            // +n1 + -n2
            if (cmp > 0)
            {
                subtraction(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
                printf("Result: ");
            }
            else
            {
                subtraction(&head2, &tail2, &head1, &tail1, &res_head, &res_tail);
                printf("Result: -");
            }
        }
    }
    //SUBTRACTION
    else if (op == '-')
    {
        if (sign1 == '+' && sign2 == '+')
        {
            if (cmp >= 0)
            {
                subtraction(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);

                printf("Result: ");
            }
            else
            {
                subtraction(&head2, &tail2, &head1, &tail1, &res_head, &res_tail);

                printf("Result: -");
            }
        }
        else if (sign1 == '-' && sign2 == '+')
        {
            //-n1 - +n2 = -(n1 + n2)
            addition(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
            printf("Result: -");
        }
        else if (sign1 == '+' && sign2 == '-')
        {
            //+n1 - (-n2) = n1 + n2
            addition(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);
            printf("Result: ");
        }
        else
        {
            //-n1 - (-n2) = n2 - n1
            if (cmp > 0)
            {
                subtraction(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);

                printf("Result: -");
            }
            else
            {
                subtraction(&head2, &tail2, &head1, &tail1, &res_head, &res_tail);

                printf("Result: ");
            }
        }
    }
    //MULTIPLICATION
    else if (op == '*')
    {
        multiplication(&head1, &tail1, &head2, &tail2, &res_head, &res_tail);

        if (sign1 != sign2)
        {
            printf("Result: -");
        }
        else
        {
            printf("Result: ");
        }
    }
    //DIVISION

    else if (op == '/')
    {
        if (head2->data == 0 && head2->next == NULL)
        {
            printf("Error: Division by zero\n");
            return FAILURE;
        }

        division(&head1, &tail1,&head2, &tail2, &res_head, &res_tail);

        if (sign1 != sign2)
        {
            printf("Result: -");
        }
        else
        {
            printf("Result: ");
        }
    }

    else
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    print_list(res_head);
    printf("\n--------------------------------------------------\n");
    return SUCCESS;
}