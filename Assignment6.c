/*
 ============================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- Searching and Sorting
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct student
{
	int rollno;
	char name[25];
	float per;
}Stud;


void accept(Stud [],int *);
void display(Stud [],int);
int validate(Stud [],int);
void selectionsort(Stud [],int);
void bubblesort(Stud [],int);
int binarysearch(Stud [],int,int);
int recursive(Stud [],int,int,int);

int main(void)
{
	Stud s[SIZE];
	int choice,cntr=0,i;
	int rno;

	while(1)
	{
		printf("Database Management System");
		printf("\n1. Accept records");
		printf("\n2. Display records");
		printf("\n3. Sort records in ascending order of roll number(Bubble Sort)");
		printf("\n4. Sort records in descending order of name(Selection Sort)");
		printf("\n5. Search by roll number(Binary Search without recursion)");
		printf("\n6. Search by roll number(Binary Search with recursion)");
		printf("\n7. Exit");
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
				printf("\nBUBBLE SORT FOR ASCENDING ORDER OF ROLL NUMBERS\n\n");
				bubblesort(s,cntr);
				display(s,cntr);
				break;
			case 4:
				printf("\n-------------------------------------------------------");
				printf("\nSELECTION SORT FOR DESCENDING ORDER OF NAMES\n\n");
				selectionsort(s,cntr);
				display(s,cntr);
				break;
			case 5:
				printf("Enter the roll number of student you want to search:-");
				scanf("%d",&rno);
				i = binarysearch(s,cntr,rno);
				if(i>=0)
				{
					printf("\nBINARY SEARCH SUCCESSFUL\n");
					printf("Details of the student are:- \n");
					printf("Roll number:- %d\n",s[i].rollno);
					printf("Name:- %s\n",s[i].name);
					printf("Percentage:- %.2f\n\n",s[i].per);
				}
				else
				{
					printf("\nBINARY SEARCH FAILED\n");
					printf("Record with roll number %d does not exist\n\n",rno);
				}
				break;
			case 6:
				printf("Enter the roll number of student you want to search:-");
				scanf("%d",&rno);
				i = recursive(s,rno,0,cntr-1);
				if(i>=0)
				{
					printf("\nBINARY SEARCH WITH RECURSION SUCCESSFUL\n");
					printf("Details of the student are:- \n");
					printf("Roll number:- %d\n",s[i].rollno);
					printf("Name:- %s\n",s[i].name);
					printf("Percentage:- %.2f\n\n",s[i].per);
				}
				else
				{
					printf("\nBINARY SEARCH WITH RECUSRION FAILED\n");
					printf("Record with roll number %d does not exist\n\n",rno);
				}
				break;
			case 7:
				return EXIT_SUCCESS;
			default:
				printf("Error in choice, try again\n\n");
		}
	}
	return EXIT_SUCCESS;
}

void accept(Stud s[],int *cntr)
{
	int flag;
	label:
	if(*cntr<SIZE)
	{
		printf("Enter the Roll Number:- ");
		scanf("%d",&s[*cntr].rollno);
		flag=validate(s,*cntr);
		if(flag==0)
		{
			printf("\nPlease enter unique roll no. The roll no. %d has already been entered\n\n",s[*cntr].rollno);
			goto label;
		}
		printf("Enter the name:- ");
		while(getchar()!='\n');
		gets(s[*cntr].name);
		printf("Enter the percentage:- ");
		scanf("%f",&s[*cntr].per);
		*cntr=*cntr+1;
		printf("\nRecord added successfully\n\n");
	}
	else
	{
		printf("\nNo more records can be added\n");
	}
}

void display(Stud s[],int cntr)
{
	int i;
	if(cntr==0)
		printf("\nPlease enter data first\n");
	else
	{
		printf("\nDATABASE:- \n");
		printf("\n-------------------------------------------------------\n");
		printf("Sr.no\tRoll no.  Name\t  Percentage");
		printf("\n-------------------------------------------------------\n");
		for(i=0;i<cntr;i++)
			printf("%3d %7d %10s %9.2f\n",i+1,s[i].rollno,s[i].name,s[i].per);
		printf("-------------------------------------------------------\n\n");
	}
}

int validate(Stud s[],int cntr)
{
	int i=0;
	if(cntr==0)
		return 1;
	for(i=0;i<cntr;i++)
	{
		if(s[i].rollno==s[cntr].rollno)
			return 0;
	}
	return 1;
}

void bubblesort(Stud s[],int cntr)
{
	int i,j,comp_cntr=0,flag,temp1=0;
	Stud temp;

	if(cntr==0)
		printf("\nPlease enter data first\n");
	else
	{
		for(i=1;i<cntr;i++)
		{
			flag=0;
			for(j=0;j<cntr-i;j++)
			{
				comp_cntr++;
				if(s[j].rollno>s[j+1].rollno)
				{
					flag=1;
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				}
			}
			for(j=0;j<cntr;j++)
			{
				printf("%d  ",s[j].rollno);

			}
			printf("Pass number:- %d\t",i);
			printf("Comparisons:- %d\n",comp_cntr-temp1);
			temp1= comp_cntr;
			if(!flag)
				break;
		}
		printf("\n-----------------------------------------------------\n");
		printf("Total number of comparisons:- %d\n",comp_cntr);
		if(comp_cntr == cntr-1)
		{
			printf("\nThis is the best case\n");
			printf("Best case time complexity is O(n)\n");
		}
		if(comp_cntr == ((cntr)*(cntr-1))/2)
		{
			printf("\nThis is the worst case\n");
			printf("Worst case time complexity is O(n^2)\n");
		}
		printf("-------------------------------------------------------\n");
	}
}

void selectionsort(Stud s[],int cntr)
{
	int i,j,min,comp_cntr=0,flag,temp1=0;
	Stud temp;

	if(cntr==0)
		printf("Please enter data first");
	else
	{
		for(i=0;i<cntr-1;i++)
		{
			flag=0;
			min=i;
			for(j=i+1;j<cntr;j++)
			{
				comp_cntr++;
				if(strcmp(s[j].name,s[min].name)>0)
				{
					flag=1;	
					min=j;
				}
			}
			temp=s[i];
			s[i]=s[min];
			s[min]=temp;
			for(j=0;j<cntr;j++)
				printf("%s  ",s[j].name);
			printf("Pass number:- %d\t",i+1);
			printf("Comparisons:- %d\n",comp_cntr-temp1);
			temp1=comp_cntr;
			if(!flag)
				break;
		}
		printf("\n-----------------------------------------------------\n");
		printf("Total comparisons:- %d\n",comp_cntr);
		printf("Time complexity for selection sort is O(n^2)\n");
		printf("-------------------------------------------------------\n");
	}
}

int binarysearch(Stud s[],int cntr,int rno)
{
	int top=0,bottom=cntr-1,mid;
	int comp_cntr=0;

	while(top<=bottom)
	{
		mid=(top+bottom)/2;
		comp_cntr++;
		if(rno==s[mid].rollno)
		{
			printf("\nNumber of comparisons are:- %d\n",comp_cntr);
			return mid;
		}
		else
		{
			if(rno<s[mid].rollno)
				bottom=mid-1;
			else
				top=mid+1;
		}
	}
	return -1;
}

int recursive(Stud s[],int rno,int top,int bottom)
{
	int mid;
	int comp_cntr=0;

	if(top>bottom)
		return -1;

	mid=(top+bottom)/2;
	comp_cntr++;
	if(rno==s[mid].rollno)
	{
		printf("\nNumber of comparisons are:- %d\n",comp_cntr);
		return mid;
	}
	else if(rno<s[mid].rollno)
		recursive(s,rno,top,mid-1);
	else
		recursive(s,rno,mid+1,bottom);
}
