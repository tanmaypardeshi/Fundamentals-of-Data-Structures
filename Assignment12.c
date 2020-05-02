/*
============================================================================
Class:- SE 10
Batch:- H 10
Roll no:- 23260
Name:- Tanmay Pardeshi
Assignment title:- Generalised Linked List
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int flag;
	union
	{
		char data[4];
		struct node *dlink;
	}u;
	struct node *next;
}node;

node *create(node *,char []);
void display(node *);


int main()
{
	node *head=NULL;
	char str[51],ask='y';
	
	while(ask=='y' || ask=='Y')
	{
		printf("\nEnter the book index string to be converted to GLL:- ");
		scanf("%s",str);
		
		printf("\nThe book index is:\n");
		head=create(head,str);
		display(head);
		while(getchar()!='\n');
		printf("\nDo you want to try again?(y/n):- ");
		scanf("%c",&ask);
	}
	return 0;
}

node *create(node *head,char str[])
{
	int i,j;
	node *temp;
	
	for(i=0;str[i]!='\0';)
	{
		if(str[i]=='(' && i==0)
		{
			head=(node*)malloc(sizeof(node));
			temp=head;
		}
		else
		{
			temp->next=(node*)malloc(sizeof(node));
			temp=temp->next;
		}
		i++;
		j=0;
		
		while(str[i]!=',' && str[i]!='(' && str[i]!=')')
		{
			temp->u.data[j]=str[i];
			i++;
			j++;
		}
		
		temp->u.data[j]='\0';
		temp->flag=0;
		
		if(str[i]=='(')
		{
			temp->next=(node*)malloc(sizeof(node));
			temp=temp->next;
			temp->flag=1;
			
			temp->u.dlink=create(NULL,&str[i]);
			
			while(str[i]!=')')
			{
				i++;
			}
			i++;
			
		}
		if(str[i]==')')
		{
			return head;
		}
	}
}

void display(node *temp)
{
	static int depth;
	depth++;
	int i;
	if(temp==NULL)
	{
		if(depth==1)
			printf("\nList is empty!\n");
		else
			printf("\nSublist is empty!\n");
	}
	
	else
	{
		while(temp!=NULL)
		{
			if(temp->flag==0)
			{
				printf("\n");
				for(i=1;i<=depth;i++)
					 printf(" ");
				printf("%s)",temp->u.data);
			}
			else
				display(temp->u.dlink);
			temp=temp->next;
		}
	}
	depth--;
}




