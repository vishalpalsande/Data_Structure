// Doubly Circular Linked List:- 	Insert First Node,
//				   	Delete First Node,
//					Insert Last Node,
//					Delete Last Node,
//					Insert At Postion,
//					Delete At Position,
//					Count Linked List,
//					Display Linked List,
//					Reverse Linked List


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,PPNODE Tail, int num)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = num;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(*Head == NULL && *Tail ==NULL)
	{
		*Tail = *Head = newn;
	}
	else
	{
		newn -> next = *Head;
		(*Head) -> prev = newn;
		*Head = newn;
	}	
	(*Tail) -> next = *Head;
	(*Head) -> prev = *Tail;
	printf("\nNode Inserted Successfully...\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,PPNODE Tail,int num)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = num;
	newn -> next = NULL;
	newn -> prev = NULL;

	if(*Head == NULL && *Tail ==NULL)
	{
		*Head = *Tail = newn;
	}
	else
	{
		newn ->prev = *Tail;
		(*Tail) -> next = newn;
		(*Tail) = newn;
	}
	
	(*Tail) -> next = *Head;
	(*Head) ->prev = *Tail;
	printf("\nNode Inserted Successfully...\n");

}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head,PNODE Tail)
{
	if(Head == NULL && Tail == NULL)
	{
		printf("\nThere is no nodes in linked list\n");
		return;
	}
	
	printf("\nNodes are:\n");
	do
	{
		printf("|%d| <=> ",Head->data);
		Head = Head->next;
	}while(Head != Tail->next);
	
	printf("Head\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head,PNODE Tail)
{
	if(Head == NULL && Tail == NULL)
		return -1;

	int iCnt = 0;
	
	do
	{
		iCnt ++;
		Head = Head->next;
	}while(Head != Tail->next);

	return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
	if(*Head == NULL && *Tail == NULL)
	{
		printf("\nThere is no nodes in linked list\n");
		return;
	}
	
	if(*Head == *Tail)
	{
		printf("\nNode %d, Deleted Successfully...\n",(*Head)->data);
		free(*Head);
		*Head = *Tail = NULL;
	}
	else
	{
		*Head = (*Head) -> next;
		printf("\nNode %d, Deleted Successfully...\n",(*Tail)->next->data);
		free((*Tail) -> next);
		(*Tail) -> next = *Head;
		(*Head) -> prev = *Tail;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head, PPNODE Tail)
{
	if(*Head == NULL && *Tail == NULL)
	{
		printf("\nThere is no nodes in linked list\n");
		return;
	}
	
	if(*Head == *Tail)
	{
		printf("\nNode %d, Deleted Successfully...\n",(*Tail)->data);
		free(*Tail);
		*Tail = *Head = NULL;
	}
	else
	{
		*Tail = (*Tail) -> prev;
		printf("\nNode %d, Deleted Successfully...\n",(*Head)->prev->data);
		free((*Head) -> prev);
		(*Tail) -> next = *Head;
		(*Head) -> prev = *Tail;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE Head, PPNODE Tail,int pos,int num)
{
	if(*Head == NULL && *Tail == NULL && pos!=1)
	{
		printf("\nThere is no nodes in linked list\n");
		return;
	}
	
	int size = Count((*Head), (*Tail));
	
	if(pos > size+1 || pos<= 0)
	{
		printf("\nInvalid Position Entered...\nNote:- Entered position between 1 to %d\n",size);
		return;
	}
	
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = num;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(pos == 1)
	{
		InsertFirst(Head, Tail, num);
	}
	else
	if(pos == size+1)
	{
		InsertLast(Head, Tail, num);
	}
	else
	{
		PNODE temp= *Head;
		
		for(int i=1;i<pos-1;i++)
		{
			temp = temp ->next;
		}
		newn->prev = temp;
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		printf("\nNode Inserted Successfully...\n");
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE Head, PPNODE Tail,int pos)
{
	if(*Head == NULL && *Tail == NULL)
	{
		printf("\nThere is no nodes in linked list\n");
		return;
	}

	int size = Count((*Head), (*Tail));
	
	if(pos > size || pos<= 0)
	{
		printf("\nInvalid Position Entered...\nNote:- Entered position between 1 to %d\n",size);
		return;
	}
	
	if(pos == 1)
	{
		DeleteFirst(Head, Tail);
	}
	else
	if(pos == size)
	{
		DeleteLast(Head, Tail);
	}
	else
	{
		PNODE temp = *Head;
		for(int i=1;i<pos-1;i++)
		{
			temp = temp -> next;
		}
		printf("\nNode %d, Deleted Successfully...\n",temp->next->data);
		temp -> next = temp -> next -> next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReverseNodes(PPNODE Head, PPNODE Tail)
{
	if(*Head == NULL && *Tail == NULL)
	{
		printf("\nThere is no nodes in linked list\n");
		return;
	}
	
	PNODE temp = *Head, current = *Head, previous = *Tail;
	
	do
	{
		temp = temp->next;
		current -> next = previous;
		previous -> prev = current;
		previous = current;
		current = temp;
	}while(temp != (*Head));
	
	*Head = previous;
	*Tail = current;
	(*Head) ->prev = *Tail;
	(*Tail) ->next= *Head;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintLine()
{
printf("\n____________________________________________________________________\n");	 			
}	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	PNODE first = NULL;
	PNODE last = NULL;
	
	int pos=0,num=0,choice=1;

	printf("\n________________Vishal Doubly Circular Linked List____________________\n\n");
	printf("\n/////////////////////////////////////////////////////////////////////////\n");
	printf("\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Insert At Position\n6.Delete At Position\n7.Display Nodes\n8.Count Nodes\n9.Reverse Linked List\n0.Exit\n");
	printf("\n/////////////////////////////////////////////////////////////////////////\n");	
	
	while(choice != 0)
	{
		printf("\nEnter ur Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the Data: ");
				scanf("%d",&num);
				InsertFirst(&first,&last,num);
				PrintLine();
				break;
			
			case 2:
				printf("Enter the data: ");
				scanf("%d",&num);
				InsertLast(&first,&last,num);
				PrintLine();
				break;
				
			case 3: 
				DeleteFirst(&first,&last);
				PrintLine();
				break;
			
			case 4:
				DeleteLast(&first,&last);
				PrintLine();
				break;	
			
			case 5:
				printf("Enter the position for insert element: ");
				scanf("%d",&pos);
				printf("Enter the data for %d position: ",pos);
				scanf("%d",&num);
				InsertAtPosition(&first,&last,pos,num);
				PrintLine();
				break;
			
			case 6:
				printf("Enter the position for Delete element: ");
				scanf("%d",&pos);
				DeleteAtPosition(&first,&last,pos);
				PrintLine();
				break;
					
			case 7:
				Display(first,last);
				PrintLine();
				break;
				
			case 8:
				if(Count(first,last) == -1)
					printf("\nThere is no node in Linked List\n");
				else
					printf("\nNumber of nodes are: %d\n",Count(first,last));
				PrintLine();
				break;
				
			case 9:
				ReverseNodes(&first,&last);
				printf("\nAfter Reverse...");
				Display(first,last);
				PrintLine();
				break;
	
			case 0:
				printf("\n_________Thank you for using this Doubly Circular linked List__________\n\n");
				break;
			
			default:
				printf("Invalid Choice entered\nNote: Please Entered choice between 1 to 9 OR 0 for Exit");
				PrintLine();
				break;
		}
	}		
	
	return 0;
}	











