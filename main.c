#include <stdio.h>
#include "apc.h"
#include <stddef.h>


int main(int argc, char *argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL, *tailR=NULL;
	int sign = 0;
	int flag = 0;

	//Validation
	if(argc != 4)
	{
		printf("Invalid Input:-( Try again...\n");
		return 0;
	}
	if(strlen(argv[2]) != 1)
	{
		printf("Invalid Input:-( Try again...\n");
		return 0;
	}
	digit_to_list(&head1,&tail1,&head2,&tail2,argv,argc,&flag);
	if(flag == 1)
	{
		return 0;
	}
	char operator=argv[2][0];


		switch (operator)
		{
			case '+':
                                
				/* call the function to perform the addition operation */
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				//printf("Addition\n");
				Dlist *temp = headR;
				while(temp != NULL)
				{
					printf("%d",temp->data);
					temp = temp->next;
				}
				printf("\n");
				break;
			case '-':
				if (strcmp(argv[1], argv[3]) == 0)
				{
					printf("0\n");
					return 0;
				}
				else{
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv,argc,&sign);
				}
					
				if(sign == 1)
				{
					printf("-");
				}
				Dlist *temp1 = headR;
				while(temp1 != NULL)
				{
					printf("%d",temp1->data);
					temp1 = temp1->next;
				}
				printf("\n");
				/* call the function to perform the subtraction operation */
				break;
			case 'X':	
				/* call the function to perform the multiplication operation */
				multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv,argc);
				break;
			case '/':	
				/* call the function to perform the division operation */
				division(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv,argc);
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}
