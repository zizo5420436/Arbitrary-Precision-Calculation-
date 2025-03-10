#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[], int argc)
{
	/* Definition goes here */
	//if argv[3] is zero, return
	if(argv[3][0] == '0' && argv[3][1] == '\0')
	{
		printf("ERROR : Undefined\n");
		return 0;
	}
	//if argv[1] is zero, return
	if(argv[1][0] == '0' && argv[1][1] == '\0')
	{
		printf("0\n");
		return 0;
	}
	//if argv[1] is less than argv[3], return
	if(strlen(argv[1]) < strlen(argv[3]))
	{
		printf("0\n");
		return 0;
	}
	//if argv[1] is equal to argv[3], but argv[1] is less than argv[3]
	if(strlen(argv[1]) == strlen(argv[3]))
	{
		if(strcmp(argv[1],argv[3]) < 0)
		{
			printf("0\n");
			return 0;
		}
	}
	 int count = 0; int sign = 0;

	 while (1)
	 {
		int flag = 0;
		*headR = NULL;
		*tailR = NULL;
		subtraction(head1, tail1, head2, tail2, headR, tailR, argv, argc, &sign);
		count++;
		
		if (*headR == NULL)
        {
            //printf("Subtraction result is zero. Exiting loop.\n");
            break;
        }
		//printf("Before updating head1, headR: ");
		//print_list(*headR);
		if (is_smaller(*headR, *head2)) {
            //printf("Dividend is now smaller than divisor. Stopping.\n");
            break;
        }
		//free_list(head1);
		*head1 = *headR;
		*tail1 = *tailR;
	 }
	 printf("%d\n", count);
	return 0;

}

int get_length(Dlist *head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}
/*void print_list(Dlist *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}*/
int is_smaller(Dlist *head1, Dlist *head2) 
{
    int len1 = get_length(head1);
    int len2 = get_length(head2);

    if (len1 < len2) return 1; 
    if (len1 > len2) return 0; 
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;
    while (temp1 && temp2) {
        if (temp1->data < temp2->data) return 1; // head1 is smaller
        if (temp1->data > temp2->data) return 0; // head1 is larger
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
}


