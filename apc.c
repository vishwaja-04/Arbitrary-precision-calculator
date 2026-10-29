#include<stdio.h>
#include"apc.h"

int validate_number_of_CLA(int argc)
{
    if(argc!=4)
    {
        //printf("ERROR: Invalid number of command line arguments\n");
        return FAILURE;
    }
    return SUCCESS;
}
int slicing_input_dll(char *str,Dlist **head, Dlist **tail)
{
    int i,digit;
    for(i=0;str[i]!='\0';i++)
    {
        digit=str[i]-'0';
        if(insert_at_last(head,tail,digit)==FAILURE)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}
void print_list(Dlist *head)
{
    Dlist *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    //printf("\n");
}

int delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;

        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}
int insert_at_first(Dlist **head, Dlist **tail,int data)
{
    Dlist *new=(Dlist *)malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("ERROR: memory allocation fails\n");
        return FAILURE;
    }
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    new->next=*head;
    (*head)->prev=new;
    *head=new;
    return SUCCESS;
}
int insert_at_last(Dlist **head, Dlist **tail,int data)
{
    Dlist *new=(Dlist *)malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("ERROR: memory allocation fails\n");
        return FAILURE;
    }
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;
    return SUCCESS;
}
int compare(Dlist *head1, Dlist *head2)
{
    Dlist *t1;
    Dlist *t2;

    int len1 = 0;
    int len2 = 0;

    t1 = head1;
    t2 = head2;

    // Count digits of number 1 
    while (t1 != NULL)
    {
        len1++;
        t1 = t1->next;
    }

    // Count digits of number 2
    while (t2 != NULL)
    {
        len2++;
        t2 = t2->next;
    }

    if (len1 > len2)
    {
        return 1;
    }

    if (len1 < len2)
    {
        return -1;
    }

    // Same number of digits 
    t1 = head1;
    t2 = head2;

    while (t1 != NULL)
    {
        if (t1->data > t2->data)
        {
            return 1;
        }

        if (t1->data < t2->data)
        {
            return -1;
        }

        t1 = t1->next;
        t2 = t2->next;
    }

    return 0;
}
