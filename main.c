/*
Name : VARUN H
Date : 06/02/2025   
Description : 
Arbitrary-precision arithmetic, also called big-num arithmetic, multiple precision arithmetic, or sometimes
infinite-precision arithmetic, indicates that calculations are performed on numbers whose digits of precision
are limited only by the available memory of the host system. . */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
int main(int argc, char *argv[])
{
    int flag1;
    // input validation
    if (argc < 4 || argc > 4)
    {
        printf("INFO: Please pass valid arguments.\nINFO: Pass minimun 3 arguments.\nUsage:./a.out operand1 [operator] operand2\n");
        return 0;
    }
    else if (!(argv[2][0] == '+' || argv[2][0] == 'x' || argv[2][0] == '/' || argv[2][0] == '-') && strlen(argv[2]) == 1)
    {
        printf("INFO: Please pass valid arguments.\n\nINFO:Pass valid operator[+,-,x,/]");
        return 0;
    }
    Operator oper;
    Dlist *head1, *head2, *head3, *head4, *head5, *head6, *tail1, *tail2, *tail3, *tail4, *tail5, *tail6;
    head1 = tail1 = head2 = tail2 = head3 = tail3 = head4 = tail4 = head5 = tail5 = NULL;
    oper = find_operation(argv[2][0]);
    if (create_list(&head1, &tail1, argv[1]) == FAILURE)
    {
        printf("ERROR:List not created\n");
        return 0;
    }
    if (create_list(&head2, &tail2, argv[3]) == FAILURE)
    {
        printf("ERROR:List not created\n");
        return 0;
    }
    // print_list(head1);
    // print_list(head2);
    switch (oper)
    {
     case add:
        // check extra test cases
        printf("After addition:\n");
        if (head1->data < 0 && head2->data < 0)
        {
            head1->data = -1 * head1->data;
            head2->data = -1 * head2->data;
            add_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
            remove_leading_zeros(&head3, &tail3);
            if(head3 != NULL)
            {
                head3->data = -1 * head3->data;
            }
        }
        else if (head1->data < 0)
        {
            head1->data = -1 * head1->data;
            if (grater_list(head1, head2) == LIST2)
            {
                //-99 + 9999
                swap(&head1, &tail1, &head2, &tail2);
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
                // head3->data = -1 * head3->data;
            }
            else
            {
                //-9999 + 99
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
                if(head3 != NULL)
                {
                    head3->data = -1 * head3->data;
                }
            }
        }
        else if (head2->data < 0)
        {
            head2->data = -1 * head2->data;
            if (grater_list(head1, head2) == LIST2)
            {
                // 99 + -9999
                swap(&head1, &tail1, &head2, &tail2);
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
                if(head3 != NULL)
                {
                    head3->data = -1 * head3->data;
                }
            }
            else
            {
                // 9999 + -99
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
                // head3->data = -1 * head3->data;
            }
        }
        else
        {
            add_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
            remove_leading_zeros(&head3, &tail3);
        }
        if(head3 == NULL)
        {
            printf("0\n");
        }
        else{
            print_list(head3);
        }
        //print_list(head3);
        break;
    // check extra test cases
    case sub:
        printf("After subtraction:\n");
        if (head1->data < 0 && head2->data < 0)
        {
            head1->data = -1 * head1->data;
            head2->data = -1 * head2->data;
            if (grater_list(head1, head2) == LIST2)
            {
                swap(&head1, &tail1, &head2, &tail2);
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
            }
            else
            {
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
                if(head3 != NULL)
                {
                    head3->data = -1 * head3->data;
                }
            
            }
        }
        else if (head1->data < 0)
        {
            head1->data = -1 * head1->data;
            add_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
            remove_leading_zeros(&head3, &tail3);
            if(head3 != NULL)
            {
                head3->data = -1 * head3->data;
            }
        }
        else if (head2->data < 0)
        {
            head2->data = -1 * head2->data;
            add_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
            remove_leading_zeros(&head3, &tail3);   
        }
        else
        {
            if (grater_list(head1, head2) == LIST2)
            {
                swap(&head1, &tail1, &head2, &tail2);
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
                if(head3 != NULL)
                {
                    head3->data = -1 * head3->data;
                }
            }
            else
            {
                sub_ele(&head1, &head2, &head3, &tail1, &tail2, &tail3);
                remove_leading_zeros(&head3, &tail3);
            }
        }
        if(head3 == NULL)
        {
            printf("0\n");
        }
        else
        {
            print_list(head3);
        }
        
        break;
    case mul:
        printf("After multiplication:\n");  
        if(head1->data < 0 && head2->data < 0)
        {
            head1->data = -1 * head1->data;
            head2->data = -1 * head2->data;
            multi(&head1, &tail1, &head2, &tail2, &head3, &tail3);
        }
        else if(head1->data < 0)
        {
            head1->data = -1 * head1->data;
            multi(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            head3->data = -1 * head3->data;
        }
        else if(head2->data < 0)
        {
            head2->data = -1 * head2->data;
            multi(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            head3->data = -1 * head3->data;
        }
        else
        multi(&head1, &tail1, &head2, &tail2, &head3, &tail3);
        remove_leading_zeros(&head3, &tail3);
        if(head3 == NULL)
        {
            printf("0\n");
        }
        else
        {
            print_list(head3);
        }
        break;
    case divide:
        printf("After division:\n");
        remove_leading_zeros(&head1, &tail1);
        remove_leading_zeros(&head2, &tail2);   
        if(head1 && head2)
        {
            if(head1->data < 0 && head2->data < 0)
            {
                head1->data = -1 * head1->data;
                head2->data = -1 * head2->data;
                divide_ele(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            }
            else if(head1->data < 0)
            {
                head1->data = -1 * head1->data;
                divide_ele(&head1, &tail1, &head2, &tail2, &head3, &tail3);
                head3->data = -1 * head3->data;
            }
            else if(head2->data < 0)
            {
                head2->data = -1 * head2->data;
                divide_ele(&head1, &tail1, &head2, &tail2, &head3, &tail3);
                head3->data = -1 * head3->data;
            }
            else
            {
                divide_ele(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            }
            print_list(head3);
        }
        else if(head1 == NULL && head2 != NULL)
        {
           printf("0\n");
        }
        else if(head2 == NULL && head1 != NULL)
        {
            printf("ERROR:Divisor is 0\n");
            return 0;
        }
        else
        {
            printf("ERROR:Dividend and Divisor both are 0\n");
            return 0;
        }
        break;
    }
    return 0;
}