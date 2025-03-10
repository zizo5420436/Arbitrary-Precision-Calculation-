#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,char *argv[],int argc)
{
    Dlist *t2 = *tail2;
    int carry, res, count = 0;
    Dlist *headRlist1 = NULL, *tailRlist1 = NULL;

    while (t2 != NULL)
    {
        Dlist *t1 = *tail1;
        Dlist *headRlist2 = NULL, *tailRlist2 = NULL; 
        carry = 0;
        // Add leading zeros for place shifting
        for (int i = 0; i < count; i++)
        {
            Dlist *zero = malloc(sizeof(Dlist));
            zero->data = 0;
            zero->prev = NULL;
            zero->next = headRlist2;

            if (headRlist2 != NULL)
            {
                headRlist2->prev = zero;
            }
            headRlist2 = zero;
            if (tailRlist2 == NULL)
            {
                tailRlist2 = zero;
            }
        }
        while (t1 != NULL)
        {
            int mul = (t1->data * t2->data) + carry;
            carry = mul / 10;
            res = mul % 10;

            // Insert result at the head of Rlist2
            Dlist *new = malloc(sizeof(Dlist));
            new->data = res;
            new->prev = NULL;
            new->next = headRlist2;

            if (headRlist2 != NULL)
            {
                headRlist2->prev = new;
            }
            headRlist2 = new;
            if (tailRlist2 == NULL)
            {
                tailRlist2 = new;
            }

            t1 = t1->prev;
        }
        // If carry there
        if (carry)
        {
            Dlist *carrynode = malloc(sizeof(Dlist));
            carrynode->data = carry;
            carrynode->prev = NULL;
            carrynode->next = headRlist2;
            if (headRlist2 != NULL)
            {
                headRlist2->prev = carrynode;
            }
            headRlist2 = carrynode;
            if (tailRlist2 == NULL)
            {
                tailRlist2 = carrynode;
            }
        }
        // Create FinalList to hold the sum of Rlist1 & Rlist2
        Dlist *headFinal = NULL, *tailFinal = NULL;
        addition(&headRlist1, &tailRlist1, &headRlist2, &tailRlist2, &headFinal, &tailFinal);
        // Update Rlist1 with the new FinalList
        headRlist1 = headFinal;
        tailRlist1 = tailFinal;

        count++;
        t2 = t2->prev;
    }

    // Assign the final accumulated result to headR
    *headR = headRlist1;
    *tailR = tailRlist1;
	//print the result
	Dlist *temp = *headR;
	while(temp != NULL)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
	printf("\n");
    return 0;
}
