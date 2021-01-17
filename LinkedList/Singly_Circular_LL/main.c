// Singly Circular Linked List:- 	Insert First Node,
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
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, PPNODE Tail, int num)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = num;
	newn -> next = NULL;
	
	if(*Head == NULL && * Tail == NULL)
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn ->next = *Head;
		*Head = newn;
	}
	(*Tail)->next = *Head;
	printf("\nNode Inserted Successfully..\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head, PPNODE Tail, int num)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = num;
	newn -> next = NULL;
	
	if(*Head == NULL && * Tail == NULL)
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail) -> next = newn;
		*Tail = newn;
	}
	(*Tail) -> next = *Head;
	printf("\nNode Inserted Successfully..\n");
}	
		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if(*Head == NULL && *Tail == NULL)
	{
		printf("\nThere is no node in Linked list\n");
		return;
	}
	
	if(*Head == *Tail)
	{
		printf("\nNode %d, Deleted Successfully.. \n",(*Head)->data);
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		printf("\nNode %d, Deleted Successfully.. \n",(*Tail)->next->data);
		free((*Tail)->next);
		(*Tail)->next = *Head;
	}
}
		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	if(*Head == NULL && *Tail == NULL)
	{
		printf("\nThere is no node in Linked list\n");
		return;
	}
	
	PNODE temp = NULL;
	
	if(*Head == *Tail)
	{
		printf("\nNode %d, Deleted Successfully.. \n",(*Tail)->data);
		free(*Tail);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		temp = *Head;
		while(temp->next != *Tail)
		{
			temp = temp->next;
		}
		printf("\nNode %d,Deleted Successfully\n",(*Tail)->data);
		free(*Tail);
		*Tail = temp;
		(*Tail)->next = *Head;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head,PNODE Tail)
{
	if(Head == NULL && Tail == NULL)
	{
		printf("\nThere is no node in Linked list\n");
		return;
	}
	
	printf("\nNodes are:\n");
	do
	{
		printf("|%d| -> ",Head->data);
		Head = Head -> next;
	}while(Head != Tail -> next);
	
	printf("Head\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head,PNODE Tail)
{
	if(Head == NULL && Tail == NULL)
	{
		return -1;
	}
	
	int iCnt = 0;

	do
	{
		Head = Head -> next;
		iCnt++;
	}while(Head != Tail -> next);
	
	return iCnt;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void InsertAtPosition(PPNODE Head,PPNODE Tail, int pos,int num)
{
	int size = 0;
	
	if(*Head == NULL && *Tail ==NULL && pos!=1 )
	{
		printf("\nThere is no element in Linked List\nPlease Enter data only in 1st position");
		return;
	}
	
	size = Count(*Head,*Tail);

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
		InsertFirst(Head, Tail, num);
	}
	else
	if(pos == size+1)
	{
		InsertLast(Head, Tail, num);
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
		printf("\nNode Inserted Successfully..\n");
	}	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE Head,PPNODE Tail,int pos)
{
	int size = 0;

	if(*Head == NULL && *Tail ==NULL)
	{
		printf("\nThere is no element in Linked List for deleting\n");
		return;
	}

	size = Count(*Head,*Tail);
	PNODE temp = NULL,temp2 =NULL;

	if( pos > size || pos <=0 )
	{
		printf("\nInvalid position Entered\n\nNote: Please Entered Position between 1 to %d\n",size);
		return;
	}
	
	if(pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else
	if(pos == size)
	{
		DeleteLast(Head,Tail);
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

void ReverseNodes(PPNODE Head,PPNODE Tail)
{
	if(*Head == NULL && *Tail ==NULL)
	{
		printf("\nThere is no element in Linked List for deleting\n");
		return;
	}

	PNODE current = *Head, previous =NULL;
	PNODE  temp = *Head;
	do
	{
		temp = temp -> next;
		current -> next = previous;
		previous = current;
		current = temp;
	}while(temp != (*Tail));
	
	current->next = previous;
	*Tail = *Head;
	*Head = current;
	(*Tail) -> next = *Head;
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

	printf("\n________________Vishal Singly Circular Linked List____________________\n\n");
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
				printf("\nAfter revese...");
				Display(first,last);
				break;
				
			case 0:
				printf("\n_________Thank you for using this Singly Circular linked List__________\n\n");
				break;
			
			default:
				printf("Invalid Choice entered\nNote: Please Entered choice between 1to 9 or 0 for Exit");
				PrintLine();
				break;
		}
	}		
	return 0;
}














