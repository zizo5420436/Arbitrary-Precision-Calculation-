#include "apc.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>  // Also needed for malloc


int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	//Addition of two numbers
	 int carry = 0;
	 Dlist *t1 = *tail1;
	 Dlist *t2 = *tail2;

	 int res = 0;

	 while(t1 != NULL || t2 != NULL || carry != 0)
	 {
		int sum = carry;
		if (t1 != NULL) 
        {
            sum = sum + t1->data;
            t1 = t1->prev;
        }
        if (t2 != NULL) 
        {
            sum = sum + t2->data;
            t2 = t2->prev;
        }
		carry = sum / 10;
		res = sum % 10;

		Dlist *new = (Dlist *)malloc(sizeof(Dlist));
		new->data = res;
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
	 return 0;
}

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[],int argc,int *flag)
{
	//validate the input
	//if the operator is not valid, return
	//if the numbers are not valid, return
	for(int i = 0; argv[1][i] != '\0'; i++)
	{
		if(argv[1][i] < '0' || argv[1][i] > '9')
		{
			*flag = 1;
			printf("Invalid Input:-( Try again...\n");
			return;
		}
	}
	for(int i = 0; argv[3][i] != '\0'; i++)
	{
		if(argv[3][i] < '0' || argv[3][i] > '9')
		{
			*flag = 1;
			printf("Invalid Input:-( Try again...\n");
			return;
		}
	}
	/* Definition goes here */
	//Converts String to List
	//argv[1] and argv[3] are the two numbers
	for(int i = 0; argv[1][i] != '\0'; i++)
	{
		//process first number
		Dlist *new = (Dlist *)malloc(sizeof(Dlist));
		new->data = argv[1][i] - '0';
		new->prev = NULL;
		new->next = NULL;

		if(*head1 == NULL)
		{
			*head1 = new;
			*tail1 = new;
		}
		else
		{
			(*tail1)->next = new;
			new->prev = *tail1;
			*tail1 = new;
		}
	}
	for(int i = 0; argv[3][i] != '\0'; i++)
	{
		//process second number
		Dlist *new = (Dlist *)malloc(sizeof(Dlist));
		new->data = argv[3][i] - '0';
		new->prev = NULL;
		new->next = NULL;

		if(*head2 == NULL)
		{
			*head2 = new;
			*tail2 = new;
		}
		else
		{
			(*tail2)->next = new;
			new->prev = *tail2;
			*tail2 = new;
		}
	}

}

