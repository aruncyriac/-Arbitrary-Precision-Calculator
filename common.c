#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
		while (head)
		{
			/* Printing the list */
			printf("%d", head->data);
			head = head->next;
		}
		printf("\n");
	}
}
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{

	// Allocating the memory for new node
	Dlist *new = malloc(sizeof(Dlist));

	// If the node is not created the returning failure
	if (!new)
	{
		return FAILURE;
	}
	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	// If the list is empty then inserting the node as first node
	if (!*head && !*tail)
	{
		*head = *tail = new;
		return SUCCESS;
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return SUCCESS;
}
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
	// Allocating the memory for new node
	Dlist *new = malloc(sizeof(Dlist));

	// If the node is not created the returning failure
	if (!new)
	{
		return FAILURE;
	}
	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	// If the list is empty then inserting the node as first node
	if (!*head && !*tail)
	{
		*head = *tail = new;
		return SUCCESS;
	}
	new->prev = *tail;
	(*tail)->next = new;
	*tail = new;
	return SUCCESS;
}
Operator find_operation(char op)
{
	switch (op)
	{
	case '+':
		return add;
		break;
	case '-':
		return sub;
		break;
	case 'x':
		return mul;
		break;
	case '/':
		return divide;
		break;
	}
}
int create_list(Dlist **head, Dlist **tail, char *op1)
{
	int i = 0, data = 0, neg = 0;
	while (op1[i] != '\0')
	{
		// check for valid operand
		if (i == 0 && (op1[0] == '-' || op1[0] == '+'))
		{
			if (op1[i] == '-')
			{
				neg = 1;
			}
			i++;
			continue;
		}
		if (!(op1[i] >= '0' && op1[i] <= '9'))
		{
			printf("Error:Invalid operand\n");
			return FAILURE;
		}
		if (neg == 1)
		{
			data = -1 * (op1[i] - '0');
			neg = 0;
		}
		else
		{
			data = op1[i] - '0';
		}
		
		i++;
		if (dl_insert_last(head, tail, data) == FAILURE)
		{
			return FAILURE;
		}
	}
	return SUCCESS;
}
int grater_list(Dlist *head1, Dlist *head2)
{
	int temp1, temp2, count1 = 0, count2 = 0,i = 0;
	while (head1 || head2)
	{
		if (head1 == NULL)
		{
			return LIST2;
		}
		if (head2 == NULL)
		{
			return LIST1;
		}
		if (i == 0 && (head1->data < 0 || head2->data < 0))
		{
			if (head1->data < 0)
			{
				temp1 = head1->data * -1;
				head1 = head1->next;
			}
			if (head2->data < 0)
			{
				temp2 = head2->data * -1;
				head2 = head2->next;
			}
			if (temp1 < temp2)
			{
				count2++;
			}
			else
			{
				count1++;
			}
		}
		if (head1->data < head2->data)
		{
			count2++;
		}
		else if(head1->data > head2->data)
		{
			count1++;
		}
		head1 = head1->next;
		head2 = head2->next;
		i++;
	}
	if (count1 > count2)
	{
		return LIST1;
	}
	else if (count1 < count2)
	{
		return LIST2;
	}
	
}
int sub_divide(Dlist **head1,Dlist **tail1,  Dlist **head2,  Dlist **tail2,Dlist **head3, Dlist **tail3)
{
	int n = 0, b = 0;
	Dlist *temp1 = *tail1, *temp2 = *tail2;
	while (temp1 || temp2)
	{
		if (b == 1)
		{
			if (temp1->data == 0)
			{
				n = 9 + temp1->data;
				b = 1;
				temp1->data = 9;
			}
			else
			{
				n = temp1->data - 1;
				b = 0;
			}
		}
		else
		{
			n = temp1->data;
		}
		if (temp2 != NULL && temp1 != NULL)
		{
			if (temp1->data < temp2->data)
			{
				n = 10 + n;
				b = 1;
			}
			n = n - temp2->data;
			if (dl_insert_first(head3, tail3, n) == SUCCESS)
			{
				temp1 = temp1->prev;
				temp2 = temp2->prev;
				continue;
			}
			else
			{
				return FAILURE;
			}
		}
		else if (temp1 != NULL)
		{
			if (dl_insert_first(head3, tail3, n) == SUCCESS)
			{
				temp1 = temp1->prev;
				continue;
			}
			else
			{
				return FAILURE;
			}
		}
	}
	return SUCCESS;
}
int delete_list(Dlist**head,Dlist**tail)
{
    if(*head==NULL)
    return FAILURE;
    if(*head==*tail)
    {
        free(*head);
        *head=*tail=NULL;
        return SUCCESS;
    }
    else
    {
    while(*head!=NULL)
    {
    Dlist *temp=*head;
    *head=(*head)->next;
    free(temp);
    }
    *tail=NULL;
    return SUCCESS;
    }
}
int add_divide(Dlist **head1, Dlist **head2, Dlist **head3, Dlist **tail1, Dlist **tail2, Dlist **tail3)
{
    int n, c = 0;
    Dlist *temp1 = *tail1, *temp2 = *tail2;
    while (temp1 || temp2)
    {
        if (temp1 && temp2)
        {
            n = temp1->data + temp2->data + c;
            c = n / 10;
            n = n % 10;
            if (dl_insert_first(head3, tail3, n) == SUCCESS)
            {	
                temp1 = temp1->prev;
                temp2 = temp2->prev;
            }
            else
            {
                return FAILURE;
            }
        }
        else if (temp1 == NULL)
        {
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

int grater_list_divide(Dlist *head1, Dlist *head2)
{
	Dlist *temp1 = head1, *temp2 = head2;
	while(temp1 && temp2)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if(temp1 != NULL && temp2 == NULL)
	{
		return LIST1;
	}
	else if(temp2 != NULL && temp1 == NULL)
	{
		return LIST2;
	}
	//for equal length
	
	while (head1 && head2)
	{
		if (head1->data < head2->data)
		{
			
			return LIST2;
		}
		else if (head1->data > head2->data)
		{
			
			return LIST1;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return SUCCESS;	
}
void remove_leading_zeros(Dlist **head, Dlist **tail)
 {
	
    
    while (*head != NULL && (*head)->data == 0)
     {
        Dlist *temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
    }
    if (*head == NULL)
    {
        *tail = NULL;
    }
}
int compare_lists(Dlist *head1, Dlist *head2) {
    // Calculate the lengths of both lists
    int length1 = calculate_length(head1);
    int length2 = calculate_length(head2);

    // Case 1: If length of list1 is smaller than list2
    if (length1 < length2) {
        return 0;  // List 1 is smaller than List 2
    }

    // Case 2: If lengths are equal, compare element by element
    if (length1 == length2) {
        while (head1 != NULL && head2 != NULL) {
            if (head1->data != head2->data) {
                return (head1->data > head2->data) ? 2 : 3;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // If all nodes are equal
        return 1;  // Lists are equal
    }

    // Case 3: If length of list1 is greater than list2
    return 2;  // List 1 is greater than List 2
}
int calculate_length(Dlist *head2)
{
    int length = 0; // Initialize length as 0
    Dlist *current = head2; // Start from the head of the list

    // Traverse through the list
    while (current != NULL) {
        length++; // Increment the count for each node
        current = current->next; // Move to the next node
    }

    return length; // Return the length
}
void free_list(Dlist **head) {
    Dlist *temp = *head;
    while (temp != NULL) {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
void insert_at_last(Dlist **head, Dlist **tail, int data) {
    // Allocate memory for the new node
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize the new node
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // If the list is empty, set both head and tail to the new node
    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        // Append the new node to the end of the list
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node; // Update the tail to the new node
    }
}