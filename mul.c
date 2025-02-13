#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
void multi(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3)
{
    Dlist *res1h=NULL;//assign pointers to null
    Dlist *res1t=NULL;
    Dlist *res3h=NULL;
    Dlist *res3t=NULL;
    Dlist *res2h=NULL;
    Dlist *res2t=NULL;
    dl_insert_first(&res2h,&res2t,0);//insert 0 to res2
    int add=0;//define a variable add
    Dlist *temp2=*tail2;//assign temp2 tto tsail2
    while(temp2!=NULL)// if temp2 is not equal to null
    {
        Dlist *temp1=*tail1;
        int carry=0;//define carry to 0
        while(temp1!=NULL)//while temp1 ot equal to null
        {
            int num=(temp2->data*temp1->data)+carry;//perform multiplication
            carry = num / 10; //calculate carry
            num = num % 10; //find reminder
            dl_insert_first(&res1h,&res1t,num);//insert at first
            temp1=temp1->prev;//traverse
        }
        if(carry)
        {
         dl_insert_first(&res1h,&res1t,carry); //if carry is present insert at first
         carry=0;  
        }
        add_divide(&res1h,&res2h,&res3h,&res1t,&res2t,&res3t);//perform addition
        temp2=temp2->prev;//temp2 traverse to previous
        add++;//increment the pointer
        temp1=*tail1;
        if(temp2==NULL)//if temp2 is null update the pointers and break
        {
            
            *head3=res3h;
            *tail3=res3t;
            break;
        }
        else
        {
        res2h=res3h;
        res2t=res3t;
        res3h=res3t=NULL;
        delete_list(&res1h,&res1t);//free the res1
        for(int i=0;i<add;i++)//append zeros
        dl_insert_first(&res1h,&res1t,0);
        
        }
    }
}