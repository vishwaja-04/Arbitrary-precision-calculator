#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Dlist;
void print_list(Dlist *res_head);
int delete_list(Dlist **head, Dlist **tail);
int compare(Dlist *head1, Dlist *head2);
int validate_number_of_CLA(int argc);
int validate_input(char *argv[]);
int slicing_input_dll(char *str,Dlist **head, Dlist **tail);
int insert_at_first(Dlist **head, Dlist **tail,int data);
int insert_at_last(Dlist **head, Dlist **tail,int data);
int addition(Dlist **head1,Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);
int subtraction(Dlist **head1,Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);
int multiplication(Dlist **head1,Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);
int division(Dlist **head1,Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **res_head, Dlist **res_tail);

#endif