#include "apc.h"

int multiplication(Dlist **head1,Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *t1;
    Dlist *t2;
    Dlist *temp1_h=NULL;
    Dlist *temp1_t=NULL;
    Dlist *temp2_h=NULL;
    Dlist *temp2_t=NULL;
    Dlist *res_h=NULL;
    Dlist *res_t=NULL;
    int carry=0;
    int prod;
    int count=0;
    int i;
    t1 = *tail1;
    t2 = *tail2;

    insert_at_first(&temp2_h, &temp2_t, 0);

    while(t2!=NULL)
    {
        while(t1!=NULL)
        {
            prod=t1->data*t2->data+carry;
            if(prod>9)
            {
                carry=prod/10;
            }
            else
            {
                carry=0;
            }
            insert_at_first(&temp1_h,&temp1_t,prod%10);
            t1=t1->prev;
        }
        if(carry>0)
        {
            insert_at_first(&temp1_h,&temp1_t,carry);
            carry=0;
        }
        if(t1==NULL)
        {
            if (t1 == NULL)
            // Add zeroes according to position
            for (i = 0; i < count; i++)
            {
                insert_at_last(&temp1_h, &temp1_t, 0);
            }
            //Add current partial product with accumulated result 
            addition(&temp1_h, &temp1_t,&temp2_h, &temp2_t, &res_h, &res_t);
            // Delete old temp1
            delete_list(&temp1_h, &temp1_t);
            // Delete old temp2
            delete_list(&temp2_h, &temp2_t);
            // Store new result in temp2 
            temp2_h = res_h;
            temp2_t = res_t;
            res_h = NULL;
            res_t = NULL;
            //Increase zero count
            count++;
            // Move t2 to previous digit
            t2 = t2->prev;
            // Reset t1
            t1 = *tail1;
            
        }
    }
    *res_head = temp2_h;
    *res_tail = temp2_t;

    return SUCCESS;


}
