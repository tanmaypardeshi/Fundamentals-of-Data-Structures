//Assignment 7 PL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct user
{
	long unsigned int mobile;
	char name[25];
	float salary;
}User;


void accept(User[],int *);
void display(User [],int);
void quicksort(User [],int,int);

int main(void)
{
	User s[SIZE];
	int choice,cntr=0,i;
	int rno;

	while(1)
	{
		printf("Database Management System");
		printf("\n1. Accept records");
		printf("\n2. Display records");
		printf("\n3. Sort records in descending order of names(quick with recursion)");
		printf("\n4. Exit");
		printf("\n\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				accept(s,&cntr);
				break;
			case 2:
				display(s,cntr);
				break;
			case 3:
				printf("\n-------------------------------------------------------");
				printf("\nQUICK SORT FOR DESCENDING ORDER OF NAMES\n\n");
				quicksort(s,0,cntr);
				display(s,cntr);
				break;
			case 4:
				return EXIT_SUCCESS;
			default:
				printf("Error in choice, try again\n\n");
		}
	}
	return EXIT_SUCCESS;
}

void accept(User s[],int *cntr)
{
	if(*cntr<SIZE)
	{
		printf("Enter the mobile:- ");
		scanf("%lu",&s[*cntr].mobile);
		printf("Enter the name:- ");
		while(getchar()!='\n'); 	
		gets(s[*cntr].name);
		printf("Enter the salary:- ");
		scanf("%f",&s[*cntr].salary);
		*cntr=*cntr+1;
		printf("\nRecord added successfully\n\n");
	}
	else
	{
		printf("\nNo more records can be added\n");
	}
}

void display(User s[],int cntr)
{
	int i;
	if(cntr==0)
		printf("\nPlease enter data first\n");
	else
	{
		printf("\nDATABASE:- \n");
		printf("\n-------------------------------------------------------\n");
		printf("Sr.no\tMobile no.  Name\t  Salary");
		printf("\n-------------------------------------------------------\n");
		for(i=0;i<cntr;i++)
			printf("%3d %13lu %7s %13.2f\n",i+1,s[i].mobile,s[i].name,s[i].salary);
		printf("-------------------------------------------------------\n\n");
	}
}


void quicksort(User s[],int l,int h)
{
	int low,high,i;
	static int count;
	User pivot_el,temp;
	
	low=l+1;
	high=h;
	pivot_el=s[l];
	
	while(low<=high)
	{
		while(strcmp(pivot_el.name,s[low].name)<0)
			low++;
		while(strcmp(pivot_el.name,s[high].name)>0)
			high--;
			
		if(low<high)
		{
			temp=s[low];
			s[low]=s[high];
			s[high]=temp;
			low++;
			high--;
		}
	}
	
	s[l]=s[high];
	s[high]=pivot_el;
	
	high--;
	count++;
	
	printf("Pass number:- %d\n",count);
	printf("Names:- ");
	for(i=0;i<h;i++)
		printf("%s  ",s[i].name);
	printf("\n");

	if(l<high)
		quicksort(s,l,high);
	if(low<h)
		quicksort(s,low,h);

}	
