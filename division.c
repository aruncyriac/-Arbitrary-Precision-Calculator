#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
void divide_ele(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3) {

    Dlist *temp1 = *head1;       
    Dlist *resh = NULL;            
    Dlist *rest = NULL;            
    Dlist *result_head = NULL;      
    Dlist *result_tail = NULL;      
    int quotient = 0;               
    int flag = 0;                   

    while (temp1 != NULL) {//traverse till temp will be null
    
        insert_at_last(&resh, &rest, temp1->data);
        temp1 = temp1->next;// update temp

        remove_leading_zeros(&resh, &rest);


        if (resh == NULL || compare_lists(resh, *head2) == 0 || compare_lists(resh, *head2) == 3) {//if list1 is less than list2 add zeros after the quotient if the quotient is non zero
            if (flag) {
                insert_at_last(&result_head, &result_tail, 0);
            }
            continue;
        }

        while (compare_lists(resh, *head2) == 1 || compare_lists(resh, *head2) == 2) {//if list1 is greater than or equal to list2
            Dlist *subh = NULL;  
            Dlist *subt = NULL; 

            subtraction(&resh, &rest, head2, tail2, &subh, &subt);  //perform subtraction
            free_list(&resh);//free the result
            resh = subh;
            rest = subt;
            quotient++;//increment he quotient
        }
        insert_at_last(&result_head, &result_tail, quotient);//insert quotient at the last
        flag = 1; //set the flag that quotient is non zero 
        quotient = 0;//reinitialize quotient to 0
    }


    if (!result_head) {
        insert_at_last(&result_head, &result_tail, 0);//if result is nulll it means list1 is less than list2 , now append zero
    }

    
    *head3 = result_head;//update the result pointers
    *tail3 = result_tail;
}


void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3) {
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0;
    int num = 0;

    // Traverse both lists from the end
    while (temp1 != NULL || temp2 != NULL) {
        int val1 = (temp1 != NULL) ? temp1->data : 0;//add leading zeros for list if they are of unequal length
        int val2 = (temp2 != NULL) ? temp2->data : 0;

        // Subtraction with borrow
        num = val1 - val2 - borrow;//perform subtraction
        if (num < 0) {
            num += 10;//if less than 0 add 10 , raise the borrow flag
            borrow = 1;
        } else {
            borrow = 0;
        }

        insert_at_first(head3, tail3, num);//insert to result list

        if (temp1 != NULL) temp1 = temp1->prev;//traverse backwards
        if (temp2 != NULL) temp2 = temp2->prev;
    }

    remove_leading_zeros(head3, tail3);//remove the leadding zeros
}


int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode=malloc(sizeof(Dlist));
    if(newnode==NULL)
    return FAILURE;
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
        return SUCCESS;
    }
    newnode->next=*head;
    (*head)->prev=newnode;
    *head=newnode;
    return SUCCESS;

}