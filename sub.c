#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
void swap(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    //function to swap two lists
    Dlist *temp = NULL;
    temp = *head1;
    ;
    *head1 = *head2;
    *head2 = temp;
    temp = *tail1;
    *tail1 = *tail2;
    *tail2 = temp;
}
int sub_ele(Dlist **head1, Dlist **head2, Dlist **head3, Dlist **tail1, Dlist **tail2, Dlist **tail3)
{
    int n = 0, b = 0;
    Dlist *temp1 = *tail1, *temp2 = *tail2;
    while (temp1 || temp2)
    {
        if (b == 1)
        {
            //borrow
            if (temp1->data == 0)
            {
                //data is 0
                n = 9 + temp1->data;
                b = 1;
                temp1->data = 9;
            }
            else
            {
                //data is not 0
                n = temp1->data - 1;
                b = 0;
            }
        }
        else
        {
            //no borrow
            n = temp1->data;
        }

        if (temp2 != NULL && temp1 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                //borrow
                n = 10 + n;
                b = 1;
            }
            //subtraction of each digit
            n = n - temp2->data;
            //store the ans new node
            if (dl_insert_first(head3, tail3, n) == SUCCESS)
            {
                //traverse the lists
                temp1 = temp1->prev;
                temp2 = temp2->prev;
            }
            else
            {
                //new node not created
                return FAILURE;
            }
        }
        else if (temp1 != NULL)
        {
            //if list2 is empty
            if(b == 1)
            {
                //borrow
                n = n;
            }
            //store the ans new node
            if (dl_insert_first(head3, tail3, n) == SUCCESS)
            {
                temp1 = temp1->prev;
                // temp2 = temp2->prev;
            }
            else
            {
                //new node not created
                return FAILURE;
            }
        }
    }
    return 0;
}