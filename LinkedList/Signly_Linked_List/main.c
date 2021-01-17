//Singly Linked List:- Insert First Node,
//			Delete First Node,
//			Insert Last Node,
//			Delete Last Node,
//			Insert At Postion,
//			Delete At Position,
//			Count,
//			Display
//			Reverse Linked List


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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	
	if( *Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	printf("\nInserted Successfully\n");
}	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head, int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = no;
	newn -> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
	printf("\nInserted Successfully\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
	PNODE temp = NULL;
	
	if(*Head == NULL)
	{
		printf("There is no nodes in linked list\n");
		return;
	}
	else
	{
		temp = *Head;
		*Head = (*Head) ->next;
		printf("%d node, deleted Successfully\n",temp->data);
		free(temp);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
	PNODE temp = NULL;
	PNODE temp2 = NULL;
	if(*Head == NULL)
	{
		printf("There is no nodes in linked list\n");
		return;
	}
	else
	if((*Head)->next == NULL)
	{
		printf("%d node, deleted Successfully\n",(*Head)->data);
		free(*Head);
		*Head = NULL;
	}
	else
	{
		temp = *Head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = NULL;
		printf("%d node, deleted Successfully\n",temp2->data);
		free(temp2);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
	if(Head == NULL)
	{
		printf("There is no node in linked list\n");
		return;
	}
	
	while(Head != NULL)
	{
		printf("|%d|->",Head->data);
		Head= Head->next;
	}
	printf(" NULL\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
	int iCnt=0;
	if(Head == NULL)
	{
		return -1;
	}
	
	while(Head != NULL)
	{
		iCnt++;
		Head= Head->next;
	}
	return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE Head,int pos,int num)
{
	int size = 0;
	
	if(*Head == NULL && pos!=1)
	{
		printf("\nThere is no element in Linked List\nPlease Enter data only in 1st position");
		return;
	}
	
	size = Count(*Head);

	if( pos > size+1 || pos <=0 )
	{
		printf("\nInvalid position Entered\n\nNote: Please Entered Position between 1 to %d\n",size);
		return;
	}
	
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = num;
	newn->next = NULL;
	PNODE temp = NULL;
	
	if(pos == 1)
	{
		InsertFirst(Head, num);
	}
	else
	if(pos == size+1)
	{
		InsertLast(Head, num);
	}
	else
	{
		temp =(*Head);
		for(int i = 1; i < pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		printf("\nInserted Successfully\n");
	}	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE Head,int pos)
{
	int size = 0;

	if(*Head == NULL)
	{
		printf("\nThere is no element in Linked List for deleting\n");
		return;
	}

	size = Count(*Head);
	PNODE temp = NULL,temp2 =NULL;

	if( pos > size || pos <=0 )
	{
		printf("\nInvalid position Entered\n\nNote: Please Entered Position between 1 to %d\n",size);
		return;
	}
	
	if(pos == 1)
	{
		DeleteFirst(Head);
	}
	else
	if(pos == size)
	{
		DeleteLast(Head);
	}
	else
	{
		temp = *Head;
		for(int i =1 ; i < pos-1 ; i++)
		{
			temp = temp ->next;
		}
		temp2 = temp->next;
		temp->next = temp->next->next;
		printf("%d node, deleted successfully",temp2->data);
		free(temp2);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReverseNodes(PPNODE Head)
{
	if(*Head ==NULL)
	{
		printf("\nThere is no node in Linked list\n");
		return;
	}
	
	PNODE temp = *Head;
	PNODE current = *Head,previous =NULL ;
	
	while(temp != NULL)
	{
		temp = temp->next;
		current -> next = previous;
		previous = current;
		current = temp;
	}
	*Head = previous;
	Display(*Head);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SortingNodes(PPNODE Head)
{
	if(*Head == NULL)
	{
		printf("\nThere is no node in Linked list\n");
		return;
	}
	
	PNODE temp = *Head;
	PNODE current = NULL;
	
	int size = 0;
	size = Count(*Head);
	int x=1;
	//printf("%d",temp->data);
	for(int i=0; x!=0 && i<size;  i++)
	{
		x=0;
		temp = *Head;
		for(int j = 0; j<size-1-i; j++)
		{
			if( (temp->data) > (temp->next->data))
			{
				printf("%d",temp->data);
				current -> data = temp->data;
				temp -> data = temp -> next -> data;		
				temp -> next -> data = current -> data;
				x=1;
			}
			temp = temp->next;
		}
	}		
}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LinePrint()
{
printf("\n____________________________________________________________________\n");	 			
}	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	PNODE first = NULL;
	printf("\n________________Vishal Singly Linked List____________________\n\n");
	printf("\n/////////////////////////////////////////////////////////////////////////\n");
	printf("\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Insert At Position\n6.Delete At Position\n7.Display\n8.Count Nodes\n9.Reverse Linked List\n0.Exit\n");
	printf("\n/////////////////////////////////////////////////////////////////////////\n");	
	int choice = 1,num=0,pos=0;
	while(choice != 0)
	{
		printf("\nEnter ur Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the Data: ");
				scanf("%d",&num);
				InsertFirst(&first,num);
				LinePrint();
				break;
			
			case 2:	
				printf("Enter the Data: ");
				scanf("%d",&num);
				InsertLast(&first,num);
				LinePrint();
				break;
			
			case 3:
				DeleteFirst(&first);
				LinePrint();
				break;
			
			case 4:
				DeleteLast(&first);
				LinePrint();
				break;
			
			case 5:
				printf("Enter the position for insert element: ");
				scanf("%d",&pos);
				printf("Enter the data for %d position: ",pos);
				scanf("%d",&num);
				InsertAtPosition(&first,pos,num);
				LinePrint();
				break;
			
			case 6:
				printf("Enter the position for Delete element: ");
				scanf("%d",&pos);
				DeleteAtPosition(&first,pos);
				LinePrint();
				break;
				
			case 7:
				printf("Nodes are:\n");
				Display(first);
				LinePrint();
				break;
			
			case 8:
				if(Count(first) == -1)
					printf("\nThere is no node in Linked List\n");
				else
					printf("\nNumber of nodes are: %d\n",Count(first));
				
				LinePrint();
				break;
			
			case 9:
				ReverseNodes(&first);
				LinePrint();
				break;
				
			case 10:
				SortingNodes(&first);
				Display(first);
				LinePrint();
				break;	
			
			case 0:
				printf("\n_________Thank you for using this Singly linked List__________\n\n");
				break;
			
			default:
				printf("Invalid Choice entered\nNote: Please Entered choice between 1to 10 or 0 for Exit");
				LinePrint();
				break;
		}
	}

	return 0;
}









