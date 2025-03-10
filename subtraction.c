#include "apc.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[], int argc,int *sign)
{
	/* Definition goes here */
	//use flag to understand -ve number

	//print head1 and head2
	Dlist *temp1 = *head1;
	while(temp1 != NULL)
	{
		//printf("%d",temp1->data);
		temp1 = temp1->next;
	}
	//printf("\n");

	Dlist *temp2 = *head2;
	while(temp2 != NULL)
	{
		//printf("%d",temp2->data);
		temp2 = temp2->next;
	}
	//printf("\n");
	
	int flag = 0;
	// swap the numbers if the second number is greater than the first number
	if (strlen(argv[1]) < strlen(argv[3])) 
	{
		flag = 1;
		// Swap head pointers
		Dlist *temp = *head1;
		*head1 = *head2;
		*head2 = temp;

		// Swap tail pointers
		temp = *tail1;
		*tail1 = *tail2;
		*tail2 = temp;
	}
	
	// If the numbers are of the same length, compare them
	else if (strlen(argv[1]) == strlen(argv[3])) 
	{
		// Compare the numbers
		if (strcmp(argv[1], argv[3]) < 0) 
		{
			flag = 1;
			// Swap head pointers
			Dlist *temp = *head1;
			*head1 = *head2;
			*head2 = temp;

			// Swap tail pointers
			temp = *tail1;
			*tail1 = *tail2;
			*tail2 = temp;
		}
		
	}
	
	// Subtract the numbers
	Dlist *t1 = *tail1;
	Dlist *t2 = *tail2;

	int sub = 0;
	while(t1 != NULL || t2 != NULL)
	{
		
		if(t1 == NULL)
		{
			sub = t2->data;
			t2 = t2->prev;
		}
		else if(t2 == NULL)
		{
			sub = t1->data;
			t1 = t1->prev;
		}
		else
		{
			if(t1->data < t2->data)
			{
				Dlist *Borrow = t1->prev;
				while(Borrow != NULL && Borrow->data == 0)
				{
					Borrow->data = 9;
					Borrow = Borrow->prev;
				}
				if(Borrow!= NULL)
				{
					Borrow->data = Borrow->data - 1;
					t1->data = t1->data + 10;
				}
				
			}
			sub = t1->data - t2->data;
			t1 = t1->prev;
			t2 = t2->prev;
		}
		Dlist *new = (Dlist *)malloc(sizeof(Dlist));
		new->data = sub;
		new->prev = NULL;
		new->next = *headR;
		if(*headR != NULL)
		{
			(*headR)->prev = new;
		}
		*headR = new;
		if(new->next == NULL)
		{
			*tailR = new;
		}
	}
	// Remove the leading zeros
	while (*headR != NULL && (*headR)->data == 0)
	 {
		Dlist *temp = *headR;
		*headR = (*headR)->next;
		if (*headR != NULL)
	    {
			(*headR)->prev = NULL;  
		} else 
		{
			*tailR = NULL;  
		}
		free(temp);
	}
	//print the result
	if(flag == 1)
	{
		*sign = 1;
	}
	if (*headR == NULL) {
		*sign = 1;
	}
	return 0;
}
