/*
============================================================================
Class:- SE 10
Batch:- H 10
Roll no:- 23260
Name:- Tanmay Pardeshi
Assignment title:- Database Management using Doubly LL
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int rollno;
	char name[50];
	float per;
	struct node *prev,*next;
};

struct node *create(struct node *);
void display(struct node *);
void displayrev(struct node *);
struct node *delete(struct node *);
void modify(struct node *);



int main(void)
{
	struct node *head=NULL;
	int choice;

	while(1)
	{
		printf("\nDatabase Management System\n");
		printf("1. Insert a record\n");
		printf("2. Delete a record\n");
		printf("3. Modify a record\n");
		printf("4. Display the records\n");
		printf("5. Display the records in reverse order\n");
		printf("6. Exit\n");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				head=create(head);
				break;
			case 2:
				head=delete(head);
				break;
			case 3:
				modify(head);
				break;
			case 4:
				display(head);
				break;
			case 5:
				displayrev(head);
				break;
			case 6:
				return EXIT_SUCCESS;
			default:
				printf("Error in choice, try again\n");

		}
	}
	return EXIT_SUCCESS;
}

struct node *create(struct node *head)
{
	struct node *newnode,*temp;

	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the roll number:- ");
	scanf("%d",&newnode->rollno);
	while(getchar()!='\n');
	printf("Enter the name:- ");
	gets(newnode->name);
	printf("Enter the percentage:- ");
	scanf("%f",&newnode->per);
	newnode->prev=newnode->next=NULL;

	temp=head;

	if(head==NULL)
	{
		head=newnode;
		printf("\nRecord added successfully\n");
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=newnode;
		newnode->prev=temp;
		printf("\nRecord added successfully\n");
	}
	return head;
}

struct node *delete(struct node *head)
{
	struct node *temp1,*temp2;
	int flag=0,rno,cntr=0;

	printf("Enter the roll number of the record to delete:- " );
	scanf("%d",&rno);
	temp1=head;
	if(rno==temp1->rollno)
	{
		temp1=temp1->next;
		temp1->prev=NULL;
		free(head);
		printf("\nRecord with roll number %d deleted successfully\n",rno);
		return temp1;
	}
	temp2=head->next;
	while(temp2!=NULL)
	{
		if(rno==temp2->rollno)
		{
			flag=1;
			break;
		}
		temp1=temp2;
		temp2=temp2->next;
	}
	if(!flag)
	{
		printf("\nRecord with roll number %d not found\n",rno);
		return head;
	}
	temp1->next=temp2->next;
	free(temp2);
	printf("\nRecord with roll number %d deleted successfully\n",rno);
	return head;
}

void modify(struct node *head)
{
	struct node *temp1;
	int flag=0,rno,cntr=0;

	printf("Enter the roll number of the record to modify:- " );
	scanf("%d",&rno);
	temp1=head;
	while(temp1!=NULL)
	{
		if(rno==temp1->rollno)
		{
			flag=1;
			break;
		}
		temp1=temp1->next;
	}
	if(!flag)
		printf("\nRecord with roll number %d not found\n",rno);

	if(flag)
	{
		while(getchar()!='\n');
		printf("Enter the new name:- ");
		gets(temp1->name);
		printf("Enter the new percentage:- ");
		scanf("%f",&temp1->per);
		printf("\nRecord with roll number %d modified successfully\n",rno);
	}
}

void display(struct node *temp)
{
	int i=1;
	if(temp==NULL)
	{
		printf("Please create a record first");
		return;
	}
	printf("---------------------------------------------------\n");
	printf("Sr.no\tRoll number\t Name\t Percentage");
	printf("\n---------------------------------------------------\n");

	while(temp!=NULL)
	{
		printf("%3d %7d %16s %10.2f\n",i,temp->rollno,temp->name,temp->per);
		temp=temp->next;
		i++;
	}
	printf("---------------------------------------------------\n");

}

void displayrev(struct node *temp)
{
	int i=1;
	if(temp==NULL)
	{
		printf("Please create a record first");
		return;
	}
	while(temp->next!=NULL)
		temp=temp->next;

	printf("---------------------------------------------------\n");
	printf("Sr.no\tRoll number\t Name\t Percentage");
	printf("\n---------------------------------------------------\n");

	while(temp!=NULL)
	{
		printf("%3d %7d %16s %10.2f\n",i,temp->rollno,temp->name,temp->per);
		temp=temp->prev;
		i++;
	}
	printf("---------------------------------------------------\n");
}

