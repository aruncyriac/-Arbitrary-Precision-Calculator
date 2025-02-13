#ifndef APC_H
#define APC_H 

#define SUCCESS 0
#define FAILURE -1
#define LIST1 -2
#define LIST2 -3
#define ONE -4
typedef enum{
    add,
    sub,
    mul,
    divide
}Operator;
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;
//function to print the list
void print_list(Dlist *head);
//function to swap the two lists
void swap(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2);
//function to insert the element at the last
int dl_insert_last(Dlist **head, Dlist **tail, int data);
//find the operation
Operator find_operation(char op);
//create the list
int create_list(Dlist **head,Dlist **tail,char *op1);
//insert the element at the first
int dl_insert_first(Dlist **head, Dlist **tail, int data);
//function to compare the two lists
int grater_list(Dlist *head1, Dlist *head2);
//function to delete the list
int delete_list(Dlist **head,Dlist **tail);
//function to add the two numbers
int add_ele(Dlist **head1,Dlist **head2,Dlist **head3, Dlist **tail1,Dlist **tail2,Dlist **tail3);
//function to subtract the two numbers
int sub_ele(Dlist **head1,Dlist **head2,Dlist **head3, Dlist **tail1,Dlist **tail2,Dlist **tail3);
int sub_divide(Dlist **head1, Dlist **head2, Dlist **head3, Dlist **tail1, Dlist **tail2, Dlist **tail3);
//function add the two numbers
int add_divide(Dlist **head1, Dlist **head2, Dlist **head3, Dlist **tail1, Dlist **tail2, Dlist **tail3);
//function to divide the two numbers
void divide_ele(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
//function to remove the leading zeros
void remove_leading_zeros(Dlist **head, Dlist **tail);
//function to insert the element at the last
void insert_at_last(Dlist **head, Dlist **tail, int data);
//function to multiply the two numbers
void multi(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3); 
//function to compare the two lists 
int compare_lists(Dlist *head1, Dlist *head2);
//function to calculate the length of the list
int calculate_length(Dlist *head2);
//function to free the list
void free_list(Dlist **head);
//function to test subtraction in division without special cases
void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3); //test
int insert_at_first(Dlist **head, Dlist **tail, int data);//test
#endif