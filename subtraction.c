#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *t1;
    Dlist *t2;
    Dlist *temp;

    Dlist *h1;
    Dlist *t1_tail;
    Dlist *h2;
    Dlist *t2_tail;

    int len1 = 0;
    int len2 = 0;
    int sign = 1;
    int diff;
    // Store actual list pointers 
    h1 = *head1;
    t1_tail = *tail1;
    h2 = *head2;
    t2_tail = *tail2;
    // Count nodes of first number
    t1 = h1;
    while (t1 != NULL)
    {
        len1++;
        t1 = t1->next;
    }

    // Count nodes of second number
    t2 = h2;

    while (t2 != NULL)
    {
        len2++;
        t2 = t2->next;
    }

    // Check which number is greater
    if (len1 < len2)
    {
        temp = h1;
        h1 = h2;
        h2 = temp;

        temp = t1_tail;
        t1_tail = t2_tail;
        t2_tail = temp;

        sign = -1;
    }
    else if (len1 == len2)
    {
        t1 = h1;
        t2 = h2;

        while (t1 != NULL)
        {
            if (t1->data > t2->data)
            {
                break;
            }

            if (t1->data < t2->data)
            {
                // Swap the numbers
                temp = h1;
                h1 = h2;
                h2 = temp;

                temp = t1_tail;
                t1_tail = t2_tail;
                t2_tail = temp;

                sign = -1;
                break;
            }

            t1 = t1->next;
            t2 = t2->next;
        }
    }

    // Start subtraction from last digit 
    t1 = t1_tail;
    t2 = t2_tail;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            t1->data = t1->data + 10;
            if (t1->prev != NULL)
            {
                t1->prev->data--;
            }
        }

        diff = t1->data - t2->data;

        // Insert result at first
        insert_at_first(res_head, res_tail, diff);

        t1 = t1->prev;
        t2 = t2->prev;
    }
    
    while (t1 != NULL)
    {
        insert_at_first(res_head, res_tail, t1->data);
        t1 = t1->prev;
    }
    // Remove leading zeroes
    while (*res_head != NULL && (*res_head)->data == 0)
    {
        temp = *res_head;

        *res_head = (*res_head)->next;

        if (*res_head != NULL)
        {
            (*res_head)->prev = NULL;
        }
        else
        {
            *res_tail = NULL;
        }

        free(temp);
    }


    return SUCCESS;
}