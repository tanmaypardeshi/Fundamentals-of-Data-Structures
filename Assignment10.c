/*
============================================================================
Class:- SE 10
Batch:- H 10
Roll no:- 23260
Name:- Tanmay Pardeshi
Assignment title:- Single Variable Polynomial using Circular LL
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node
{
	int exp; 
	float coef;  
	struct node *next;
};


struct node *create(struct node  *);
struct node *getnode(struct node *);
struct node *insert(struct node *,int,float);
void display(struct node *);
struct node *add(struct node *,struct node *);
struct node *multiply(struct node *,struct node *);
float evaluate(struct node *,float);
int power(int,int);


int main(void)
{

	struct node *poly1=NULL,*poly2=NULL,*poly3=NULL;
	int choice;
	float answer,x;
	
	while(1)
	{
		printf("\nOperations on Polynomials Using CLL\n");
		printf("1. Create Polynomial\n");
		printf("2.Add 2 polynomials\n");
		printf("3.Multiply 2 polynomials\n");
		printf("4.Evaluate polynomial\n");
		printf("5.Exit\n");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice); 
		
		switch(choice)
		{
			case 1:
				poly1=NULL;
				poly2=NULL;
				printf("\nEnter details of 1st polynomial:- \n");
				poly1=create(poly1);

				printf("\nEnter details of 2nd polynomial:- \n");
				poly2=create(poly2);

				printf("\n\nPolynomial 1 is :- ");
				display(poly1);

				printf("\n\nPolynomial 2 is :- ");
				display(poly2);
				break;

			case 2:
				poly3=NULL;
				printf("\n\nPolynomial 1 is :- ");
				display(poly1);

				printf("\n\nPolynomial 2 is :- ");
				display(poly2);

				printf("\n\nAddition of the polynomials is :- ");
				poly3=add(poly1,poly2);
				display(poly3);
				break;

			case 3:
				poly3=NULL;
				printf("\n\nPolynomial 1 is :- ");
				display(poly1);

				printf("\n\nPolynomial 2 is :- ");
				display(poly2);

				printf("\n\nMultiplication of the polynomials is :- ");
				poly3=multiply(poly1,poly2);
				display(poly3);
				break;

			case 4:
				printf("\n\nEnter details of the polynomial:- ");
				poly1=NULL;
				poly1=create(poly1);

				printf("\n\nEnter the value of x:- ");
				scanf("%f",&x);

				answer=evaluate(poly1,x);
				printf("\n\nValue of ");
				display(poly1);
				printf("\nfor x=%.3f is %0.4f",x,answer);
				break;

			case 5:
				return EXIT_SUCCESS;
			
			default:
				printf("\nError in choice, try again\n");
		}
	}
	return EXIT_SUCCESS;
}

struct node *create(struct node *head)
{
	int n,i,exp;
	float coef;
	printf("\nEnter number of terms:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    printf("\nEnter the exponent:- ");
		scanf("%d",&exp);
		printf("\nEnter the coefficient:- ");
		scanf("%f",&coef);
		head=insert(head,exp,coef);
	}
	return head;
}

struct node *getnode(struct node *temp)  
{
	temp=(struct node *)malloc(sizeof(struct node)); 
	temp->next=NULL;
	return temp;
}

struct node *insert(struct node *head,int expo1,float coef1)
{
	struct node *p=NULL,*q=NULL,*t=NULL;
	p=getnode(p);
	p->exp=expo1;
	p->coef=coef1;
	if(head==NULL) 
	{
		head=p;
		head->next=head; 
		return head;
	}

	if(expo1>head->exp)
	{
		p->next=head;
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=p;
		head=p;
		return head;
	}
	q=head;

	while(q->next != head && expo1 <= q->next->exp)
		q=q->next;
	
	if(p->exp==q->exp)
	{
		q->coef=q->coef + coef1;
		free(p);
	}
	else
	{
		p->next=q->next;
		q->next=p;
	}
	return head;
}

void display(struct node *head)
{
	 struct node *temp;
		if(head==NULL)
			printf("\n\nEmpty list\n");
		else
		{
			temp=head;
			do
			{
				if(temp->exp==0) 
					printf("(%.2f)",temp->coef);
				else
					printf("(%.2fx^%d)",temp->coef,temp->exp);
				if(temp->next!=head)
					printf("+");
				else
					printf(".");

				temp=temp->next;
			}while(temp!=head);
		}
}

struct node *add(struct node *poly1,struct node *poly2)
{
	struct node *t=NULL,*poly3=NULL;

	if(poly1==NULL && poly2==NULL)
	{
		printf("\nEmpty lists present.Cannot add empty lists!");
		return poly1;
	}

	if(poly1!=NULL) 
		t=poly1;
	do
	{
		poly3=insert(poly3,t->exp,t->coef);
		t=t->next;
	}while(t!=poly1);

	if(poly2!=NULL)
		t=poly2;
	do
	{
		poly3=insert(poly3,t->exp,t->coef);
		t=t->next;
	}while(t!=poly2);

	return poly3;
}

struct node *multiply(struct node *poly1,struct node *poly2)
{
	struct node *poly3=NULL;
	struct node *p1=NULL,*p2=NULL;
	if(poly1==NULL && poly2==NULL)
	{
		printf("\nEmpty lists present.Cannot multiply empty lists");
		return poly3;
	}

	p2=poly2;
	do
	{
		p1=poly1;
		do
		{
			poly3=insert(poly3,p1->exp+p2->exp,(p1->coef)*(p2->coef));
			p1=p1->next; 
		}while(p1!=poly1);

		p2=p2->next;
	}while(p2!=poly2);
	return poly3;
}

float evaluate(struct node *head,float x)
{
	struct node *p;
	float ans=0;
	p=head;
	do
	{
		ans+=p->coef*power(x,p->exp); 
		p=p->next;
	}while(p!=head);
	return ans;
}

int power(int x, int y)
{
	int n=1;
	for(int i=0;i<y;i++)
		n=n*x;
	return n;
}

