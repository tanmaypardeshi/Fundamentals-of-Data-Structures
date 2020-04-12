/*
============================================================================
Class:- SE 10
Batch:- H 10
Roll no:- 23260
Name:- Tanmay Pardeshi
Assignment title:- Singly Linked List
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *next;
};

struct node *create(struct node *);
void display(struct node *);
struct node *insertatbeg(struct node *);
void insertatend(struct node *);
struct node *insertatpos(struct node *);
struct node *deleteatbeg(struct node *);
struct node *deleteatend(struct node *);
struct node *deleteatpos(struct node *);
void displayrev(struct node *);
struct node *revert(struct node *);


int main(void)
{
	int choice;
	struct node *head;
	head = NULL;

	while(1)
	{
		printf("\n\nOperations on Singly Linked List\n");
		printf("1. Create linked list\n");
		printf("2. Display the linked list\n");
		printf("3. Insert a node at the beginning\n");
		printf("4. Insert a node at the end\n");
		printf("5. Insert a node at any position\n");
		printf("6. Delete a node at the beginning\n");
		printf("7. Delete a node at then end\n");
		printf("8. Delete a node at any position\n");
		printf("9. Display the linked list in reverse order\n");
		printf("10. Revert the linked list\n");
		printf("11. Exit the program\n");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				head=create(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				head=insertatbeg(head);
				break;
			case 4:
				insertatend(head);
				break;
			case 5:
				head=insertatpos(head);
				break;
			case 6:
				head = deleteatbeg(head);
				break;
			case 7:
				head=deleteatend(head);
				break;
			case 8:
				head=deleteatpos(head);
				break;
			case 9:
				printf("Linked list in the reverse order is:- ");
				displayrev(head);
				break;
			case 10:
				head=revert(head);
				printf("Linked list reverted successfully");
				break;
			case 11:
				return EXIT_SUCCESS;
			default:
				printf("\nError in choice, try again\n");
		}
	}
	return EXIT_SUCCESS;
}

struct node *create(struct node *head)
{
	struct node *newnode, *temp;
	char ask='y';
	while(ask=='y' || ask=='Y')
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data for the newnode:- ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			temp=newnode;
			head=newnode;
		}
		else
		{
			temp->next = newnode;
			temp=newnode;
		}
		while(getchar()!='\n');
		printf("Do you want to add more nodes?(y/n):- ");
		scanf("%c",&ask);
	}
	return head;
}

void display(struct node *temp)
{
	if(temp==NULL)
		printf("\nPlease create a linked list first\n\n");
	else
	{
		printf("Elements of the linked list are:- ");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}

struct node *insertatbeg(struct node *head)
{
	struct node *newnode;

	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for the newnode:- ");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head = newnode;
	printf("\nNode inserted successfully at the beginning\n");
	return head;
}

void insertatend(struct node *head)
{
	struct node *newnode,*temp;
	newnode= (struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode:- ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;
	printf("\nNode inserted successfully at the end\n");
}

struct node *insertatpos(struct node *head)
{
	struct node *temp1,*temp2,*newnode;
	int pos,cntr=0;
	printf("Enter the position of node:-");
	scanf("%d",&pos);

	if(pos==1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data for newnode:- ");
		scanf("%d",&newnode->data);
		newnode->next = head;
		printf("\nNode inserted at position %d inserted successfully\n",pos);
		return newnode;
	}
	temp1=head;
	while(temp1!=NULL)
	{
		cntr++;
		temp1=temp1->next;
	}
	if(pos>cntr+1 || pos<1)
	{
		printf("\nInvalid position\n");
		return head;

	}
	cntr=2;
	temp1=head;
	temp2=head->next;

	while(temp2!=NULL)
	{
		if(pos==cntr)
			break;
		cntr++;
		temp1=temp2;
		temp2=temp2->next;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode:- ");
	scanf("%d",&newnode->data);
	temp1->next=newnode;
	newnode->next=temp2;
	printf("\nNode inserted at position %d inserted successfully\n",pos);
	return head;
}

struct node *deleteatbeg(struct node *head)
{
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
	printf("\nNode at beginning deleted successfully\n\n");
	return head;
}

struct node *deleteatend(struct node *head)
{
	struct node *temp;
	if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	temp=head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	free(temp->next);
	temp->next=NULL;
	printf("\nNode at end deleted successfully\n\n");
	return head;
}

struct node *deleteatpos(struct node *head)
{
	struct node *temp1,*temp2;
	int pos,cntr=0;

	printf("Enter the position of the node to delete:- ");
	scanf("%d",&pos);

	if(pos==1)
	{
		temp1=head;
		head=head->next;
		free(temp1);

		printf("\nNode inserted at position %d successfully\n",pos);
		return head;
	}
	temp1=head;
	while(temp1!=NULL)
	{
		cntr++;
		temp1=temp1->next;
	}
	if(pos>cntr || pos<1)
	{
		printf("\nInavlid position\n");
		return head;
	}
	cntr=2;
	temp1=head;
	temp2=head->next;
	while(temp2!=NULL)
	{
		if(pos==cntr)
			break;
		cntr++;
		temp1=temp2;
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	free(temp2);
	printf("\nNode inserted at position %d deleted successfully\n",pos);
	return head;
}

void displayrev(struct node *head)
{
	if(head!=NULL)
	{
		displayrev(head->next);
		printf("%d\t",head->data);
	}

}

struct node *revert(struct node *head)
{
	struct node *prev,*current;
	
	if(head!=NULL)
	{
		prev=head;
		head=head->next;
		current=head;
		prev->next=NULL;
		
		while(head!=NULL)
		{
			head=head->next;
			current->next=prev;
			prev=current;
			current=head;
		}
	}
	head=prev;
	return head;
}
		
		
		
		
		
		
		
		

