// Queue Using Linked List:-	Enqueue
//					Dequeue
//					Display
//					Count
//					Reverse

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Enqueue(PPNODE Head,int num)
{
	PNODE newn = NULL, temp = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = num;
	newn -> next = NULL;
	
	if( (*Head) == NULL)
	{
		*Head = newn;
	}
	else
	{
		temp = *Head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp -> next = newn;
	}
	printf("\nNode Enqueue Successfully...\n");
} 		
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Dequeue(PPNODE Head)
{
	if(*Head == NULL)
	{
		printf("\nThere is no node in Queue\n");
		return;
	}
	
	PNODE temp = *Head;
	
	if( (*Head)->next == NULL)
	{
		*Head = NULL;
	}
	else
	{
		*Head = (*Head) -> next;
	}
	
	printf("\nNode %d, Dequeue Successfully...\n",temp->data);
	free(temp);	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
	if(Head == NULL)
	{
		printf("\nThere is no node in Queue\n");
		return;
	}

	printf("\nNodes are:\n");
	while(Head != NULL)
	{
		printf("|%d| -> ",Head -> data);
		Head = Head -> next;
	}
	printf("NULL\n");	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
	if(Head == NULL)
	{
		printf("\nThere is no node in Queue\n");
		return -1;
	}
	
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head -> next;
	}
	
	return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReverseQueue(PPNODE Head)
{
	if(*Head == NULL)
	{
		printf("\nThere is no node in Queue\n");
		return;
	}
	
	PNODE current = *Head , temp = *Head , previous  = NULL;
	
	while(temp != NULL)
	{
		temp = temp -> next;
		current -> next = previous;
		previous = current;
		current = temp;
	}
	
	*Head = previous;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintLine()
{
	printf("\n____________________________________________________________\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	PNODE first = NULL;
	int num = 0,choice =1;
	
	printf("\n______________________ViSHAL Queue Application______________________\n");
	
	printf("\n----------------------------------------------------------------------\n");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Count\n5.Reverse\n0.Exit\n");
	printf("\n----------------------------------------------------------------------\n");


	while(choice != 0)
	{
		
		printf("\nEnter Any Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter any data: ");	
				scanf("%d",&num);
				Enqueue(&first,num);
				PrintLine();
				break;	
			
			case 2:
				Dequeue(&first);
				PrintLine();
				break;
			
			case 3:
				Display(first);
				PrintLine();
				break;
			
			case 4:
				if(Count(first) == -1)
				{
					printf("\nThere is no node in stack\n");
				}
				else
				{
					printf("\nNumber of nodes in stack are: %d\n",Count(first));
				}
				PrintLine();
				break;
			
			case 5:
				ReverseQueue(&first);
				printf("\nAfter Reversing queue nodes are:\n");
				Display(first);
				PrintLine();
				break;
				
			case 0:
				printf("\n______________Thank you for using this Queue Application_______________\n\n");
				break;
			
			default:
				printf("\nInvalid Choice Entered\nNote: Please Enter Choice Between 1 to 5 OR 0 for exit\n");
				break;	
		}
	}
	
	return 0;
	
}





