#include<stdio.h>
#include"apc.h"

int addition(Dlist **head1,Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail)
{
    Dlist *temp1=*tail1;
    Dlist *temp2=*tail2;
    int carry=0;
    int sum;
    //c1:same no.of nodes
    while(temp1!=NULL && temp2!=NULL)
    {
        sum=temp1->data+temp2->data+carry;
        if(sum>9)
        {
            carry=1;
            sum=sum-10;
        }
        else
        {
            carry=0;
        }
        if(insert_at_first(res_head,res_tail,sum)==FAILURE)
        {
            return FAILURE;
        }
        temp1=temp1->prev;
        temp2=temp2->prev;
    }
    while(temp1!=NULL)
    {
        sum=temp1->data+carry;
        if(sum>9)
        {
            carry=1;
            sum=sum-10;
        }
        else
        {
            carry=0;
        }
        if(insert_at_first(res_head,res_tail,sum)==FAILURE)
        {
            return FAILURE;
        }
        temp1=temp1->prev;
    }
    while(temp2!=NULL)
    {
        sum=temp2->data+carry;
        if(sum>9)
        {
            carry=1;
            sum=sum-10;
        }
        else
        {
            carry=0;
        }
        if(insert_at_first(res_head,res_tail,sum)==FAILURE)
        {
            return FAILURE;
        }
        temp2=temp2->prev;
    }
    if(carry==1)
    {
        if(insert_at_first(res_head,res_tail,carry)==FAILURE)
        {
            return FAILURE;
        }
    }
    return SUCCESS;

}
