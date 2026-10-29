#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *t1;
    Dlist *rem_h = NULL;
    Dlist *rem_t = NULL;

    Dlist *sub_h = NULL;
    Dlist *sub_t = NULL;

    Dlist *temp;
    int count;
    int len1;
    int len2;
    Dlist *p1;
    Dlist *p2;
    //Check division by zero
    if (*head2 == NULL)
    {
        return FAILURE;
    }
    if ((*head2)->data == 0 && (*head2)->next == NULL)
    {
        return FAILURE;
    }
    t1 = *head1;
    while (t1 != NULL)
    {
        //Take one digit from front of h1 and add it to remainder
        insert_at_last(&rem_h, &rem_t, t1->data);
        t1 = t1->next;
        // Remove unnecessary leading zeroes from remainder 
        while (rem_h != NULL && rem_h->data == 0 && rem_h->next != NULL)
        {
            temp = rem_h;
            rem_h = rem_h->next;
            rem_h->prev = NULL;

            free(temp);
        }
        //Find length of remainder
        len1 = 0;
        p1 = rem_h;

        while (p1 != NULL)
        {
            len1++;
            p1 = p1->next;
        }
        //Find length of divisor
        len2 = 0;
        p2 = *head2;

        while (p2 != NULL)
        {
            len2++;
            p2 = p2->next;
        }
        //Check rem < h2
        if (len1 < len2)
        {
            insert_at_last(res_head, res_tail, 0);
        }
        else
        {
            //If both have same number of digits, compare digit by digit.
            int cmp = 0;
            if (len1 == len2)
            {
                p1 = rem_h;
                p2 = *head2;

                while (p1 != NULL)
                {
                    if (p1->data > p2->data)
                    {
                        cmp = 1;
                        break;
                    }
                    if (p1->data < p2->data)
                    {
                        cmp = -1;
                        break;
                    }
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
            else
            {
                cmp = 1;
            }
            //rem < h2
            if (cmp < 0)
            {
                insert_at_last(res_head, res_tail, 0);
            }
            else
            {
                //rem >= h2
                count = 0;
                while (1)
                {
                    //Compare rem and divisor again
                    len1 = 0;
                    p1 = rem_h;

                    while (p1 != NULL)
                    {
                        len1++;
                        p1 = p1->next;
                    }

                    len2 = 0;
                    p2 = *head2;

                    while (p2 != NULL)
                    {
                        len2++;
                        p2 = p2->next;
                    }

                    if (len1 < len2)
                    {
                        break;
                    }

                    if (len1 == len2)
                    {
                        p1 = rem_h;
                        p2 = *head2;
                        cmp = 0;

                        while (p1 != NULL)
                        {
                            if (p1->data > p2->data)
                            {
                                cmp = 1;
                                break;
                            }

                            if (p1->data < p2->data)
                            {
                                cmp = -1;
                                break;
                            }

                            p1 = p1->next;
                            p2 = p2->next;
                        }

                        if (cmp < 0)
                        {
                            break;
                        }
                    }
                    //rem >= h2 or rem = rem - h2
                    sub_h = NULL;
                    sub_t = NULL;
                    subtraction(&rem_h, &rem_t, head2, tail2, &sub_h, &sub_t);
                    //Delete old remainder
                    delete_list(&rem_h, &rem_t);

                    //Subtraction result becomes new remainder
                    rem_h = sub_h;
                    rem_t = sub_t;

                    sub_h = NULL;
                    sub_t = NULL;

                    count++;
                }
                //Insert quotient digit
                insert_at_last(res_head, res_tail, count);
            }
        }
    }
    //Remove leading zeroes from quotient
    while (*res_head != NULL && (*res_head)->data == 0 && (*res_head)->next != NULL)
    {
        temp = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(temp);
    }

    //Update result tail
    *res_tail = *res_head;

    if (*res_tail != NULL)
    {
        while ((*res_tail)->next != NULL)
        {
            *res_tail = (*res_tail)->next;
        }
    }
    //Delete final remainder
    delete_list(&rem_h, &rem_t);
    return SUCCESS;
}