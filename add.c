#include <stdio.h>
#include "apc.h"
int add_ele(Dlist **head1, Dlist **head2, Dlist **head3, Dlist **tail1, Dlist **tail2, Dlist **tail3)
{
    //addition of two numbers
    int n, c = 0;
    Dlist *temp1 = *tail1, *temp2 = *tail2;
    while (temp1 || temp2)
    {
        if (temp1 && temp2)
        {
            //addition of each digit
            n = temp1->data + temp2->data + c;
            c = n / 10; //carry
            n = n % 10;//answer
            if (dl_insert_first(head3, tail3, n) == SUCCESS)
            {
                //store the ans new node
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
        else if (temp1 == NULL)
        {
            //if list1 is empty
            n = temp2->data + c;
            c = n / 10;
            n = n % 10;
            if (dl_insert_first(head3, tail3, n) == SUCCESS)
            {
                // temp1 = temp1->prev;
                temp2 = temp2->prev;
            }
            else
            {
                return FAILURE;
            }
        }
        else if (temp2 == NULL)
        {
            //if list2 is empty
            n = temp1->data + c;
            c = n / 10;
            n = n % 10;
            if (dl_insert_first(head3, tail3, n) == SUCCESS)
            {
                temp1 = temp1->prev;
                // temp2 = temp2->prev;
            }
            else
            {
                return FAILURE;
            }
        }
    }
    if (c != 0)
    {
        //carry is left
        if (dl_insert_first(head3, tail3, c) == SUCCESS)
        {
           // temp1 = temp1->prev;
            // temp2 = temp2->prev;
            return SUCCESS;
        }
        else
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}