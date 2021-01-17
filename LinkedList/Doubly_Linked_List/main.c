//Doubly Linked List:- Insert First Node,
//			Delete First Node,
//			Insert Last Node,
//			Delete Last Node,
//			Insert At Postion,
//			Delete At Position,
//			Display All Nodes,
//			Count All Nodes,
//			Reverse Linked List
			

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node  NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, int num)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data=num;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
		printf("\nNode Inserted Successfully\n");
	}
	else
	{
		newn->next = (*Head);
		(*Head)->prev = newn;
		*Head = newn;
		printf("\nNode Inserted Successfully\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int num)
{
	PNODE newn = NULL;
	PNODE temp =NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = num;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
		printf("\nNode Inserted Successfully\n");
	}
	else
	{
		temp = *Head;
		while(temp -> next!= NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newn;
		newn->prev = temp;
		printf("\nNode Inserted Successfully\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{	
	if(*Head == NULL)
	{	
		printf("\nThere is no node in LinkedList\n");
		return;
	}
	
	if((*Head) ->next == NULL)
	{
		printf("\n%d Nodes Data, Deleted Succesfully\n",(*Head)->data);
		free(*Head);
		*Head = NULL;
	}
	else
	{	
		*Head = (*Head) -> next;
		printf("\n%d Nodes Data, Deleted Succesfully\n",(*Head)->prev->data);
		free((*Head) ->prev);
		(*Head) -> prev = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
	PNODE temp = 0;
	if(*Head == NULL)
	{
		printf("\nThere is no node in LinkedList\n");
		return;
	}
	
	if((*Head)->next == NULL)
	{
		printf("\n%d Nodes Data, Deleted Successfully\n",(*Head)->data);
		free(*Head);
		*Head = NULL;
	}
	else
	{
		temp = *Head;
		while(temp->next != NULL)
		{
			temp = temp-> next;
		}
		
		printf("\n%d Nodes Data, Deleted Successsfully\n",temp->data);
		temp -> prev ->next = NULL;
		free(temp);
	}
}
		
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
	if(Head == NULL)
	{
		printf("\nThere is no node in LinkedList\n");
		return;
	}
	printf("\nNodes are:\n");
	while(Head!=NULL)
	{
		printf("|%d| <=> ",Head->data);
		Head= Head->next;
	}
	printf("NULL\n");
}	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
	int iCnt = 0;
	if(Head == NULL)
	{
		return -1;
	}
	
	while(Head!=NULL)
	{
		iCnt++;
		Head= Head->next;
	}
	return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

void InsertAtPosition(PPNODE Head,int pos,int num)
{
	if( (*Head) == NULL && pos != 1)
	{
		printf("\nThere is no node in LinkedList\n");
		return;
	}
	int size = Count(*Head);
	PNODE temp = NULL, newn=NULL;
	
	if(pos > size+1 || pos<=0)
	{	
		printf("Invalid postion Entered\nNote: Please Entered postion between 1 to %d\n",size);
		return;
	}
	
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
		temp = *Head;
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data= num;
		newn->next=NULL;
		newn->prev=NULL;
		
		for(int i=1;i<pos-1;i++)
		{
			temp = temp ->next;
		}
		
		newn->next = temp->next;
		temp->next->prev = newn;
		newn->prev=temp;
		temp->next = newn;
		printf("\nNode Inserted Successfully\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE Head,int pos)
{
	if( (*Head) == NULL && pos != 1)
	{
		printf("\nThere is no node in LinkedList\n");
		return;
	}
	int size = Count(*Head);
	PNODE temp = NULL;
	
	if(pos > size || pos<=0)
	{
		printf("Invalid postion Entered\nNote: Please Entered postion between 1 to %d\n",size);
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
		for(int i=1; i<pos-1; i++)
		{
			temp = temp->next;
		}
		
		printf("\n%d Nodes Data,Deleted Successfully\n",temp->next->data);
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}
}	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReverseNodes(PPNODE Head)
{
	if( *Head == NULL)
	{
		printf("\nThere is no node in LinkedList for Reverse\n");
		return;
	}
	
	PNODE temp = *Head,current =*Head,previous = NULL;
	
	while(temp != NULL)
	{
		temp = temp->next;
		current -> next = previous;
		current -> prev = temp;
		previous = current;
		current = temp;
	}
	
	*Head = previous;
	Display(*Head);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LinePrint()
{
printf("\n____________________________________________________________________\n");	 			
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	PNODE first = NULL;
	int choice = 1, num=0, pos= 0;
	printf("\n________________Vishal Doubly Linked List____________________\n\n");
	printf("\n/////////////////////////////////////////////////////////////////////////\n");
	printf("\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Insert At Position\n6.Delete At Position\n7.Display\n8.Count Nodes\n9.Reverse Linked List\n0.Exit\n");
	printf("\n/////////////////////////////////////////////////////////////////////////\n");	
	 
	 while(choice != 0)
	 {	
	 	printf("\nEnter Your Choice: ");
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
				printf("\nEnter the position u want to insert: ");
				scanf("%d",&pos);
				printf("Enter the data: ");
				scanf("%d",&num);
				InsertAtPosition(&first,pos,num);
				LinePrint();
				break;
			
			case 6:
				printf("\nEnter the position u want to Delete: ");
				scanf("%d",&pos);
				DeleteAtPosition(&first,pos);
				LinePrint();
				break;
							
			case 7:
				Display(first);
				LinePrint();
				break;
				
			case 8:
				if(Count(first) == -1)
					printf("\nThere is no node in LinkedList\n");
				else
					printf("\nNumber of elements are: %d\n",Count(first));
				LinePrint();
				break;
				
			case 9:
				ReverseNodes(&first);
				LinePrint();
				break;
				
			case 0:
				printf("\n\n__________Thank You For Using This Doubly Linked List____________\n\n");
				break;
					
			default:
				printf("\nInvalid Choice Entered\nNote: Please Entered choice between 1 to 9 or 0 for Exit\n");
				LinePrint();
				break;
		}
	}
			
	return 0;
}













