/*
 ============================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- Database Management
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct employee
{
	int empid,age;
	char name[25];
	float sal;
}Emp;

void accept(Emp [],int,int *);
void display(Emp [],int);
int search(Emp [],int,int);
int modify(Emp [],int,int);
int deleterecord(Emp [],int,int *);
int validate(Emp [],int);

int main(void)
{
	Emp e[SIZE];
	int noe,choice,id,no;
	int cntr=0;
	printf("Enter the number of employees you want to store in your database:- ");
	scanf("%d",&noe);

	while(1)
	{
		printf("\nDatabase Management System");
		printf("\n1. Add a record");
		printf("\n2. Display records");
		printf("\n3. Search for a record");
		printf("\n4. Modify a record");
		printf("\n5. Delete a record");
		printf("\n6. Exit");
		printf("\n\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				accept(e,noe,&cntr);
				break;
			case 2:
				printf("---------------------------------------------------\n");
				printf("Sr.no\tEmp.ID\t  Name\t  Salary\t Age");
				printf("\n---------------------------------------------------\n");
				display(e,cntr);
				printf("---------------------------------------------------\n");
				break;
			case 3:
				printf("Enter the empid to search:- ");
				scanf("%d",&id);
				no=search(e,id,cntr);
				if(no!=0)
				{
					printf("\nSearch Successful!\nDetails of Employee are:- \n");
					printf("Emp. Id:- %d\n",e[no-1].empid);
					printf("Name:- %s\n",e[no-1].name);
					printf("Salary:- %.2f\n",e[no-1].sal);
					printf("Age:- %d\n",e[no-1].age);
				}
				else
				{	printf("\nSearch Unsuccessful\n");
					printf("Record with empid %d not found\n",id);
				}
				break;
			case 4:
				printf("Enter the empid to modify:- ");
				scanf("%d",&id);
				no=modify(e,id,cntr);
				if(no!=0)
				{
					printf("\nModification Successful!\n");
					printf("New details of Employee are:- \n");
					printf("Emp. Id:- %d\n",e[no-1].empid);
					printf("Name:- %s\n",e[no-1].name);
					printf("Salary:- %.2f\n",e[no-1].sal);
					printf("Age:- %d\n",e[no-1].age);
				}
				else
					printf("\nRecord with empid %d not found\n",id);
				break;
			case 5:
				printf("Enter the empid whose record is to be deleted:- ");
				scanf("%d",&id);
				no = deleterecord(e,id,&cntr);
				if(no==1)
					printf("Record with empid %d deleted successfully\n",id);
				else
					printf("Record with empid %d not found\n",id);
				int validateid(Emp  [],int);
				break;
			case 6:
				return EXIT_SUCCESS;
			default:
				printf("Error in choice,try again\n");
		}
	}

	return EXIT_SUCCESS;
}

void accept(Emp e[],int noe,int *cntr)
{
	int flag;
	if(*cntr<noe)
	{
		printf("Enter the Emp. ID:- ");
		scanf("%d",&e[*cntr].empid);
		flag=validate(e,*cntr);
		if(flag==0)
		{
			printf("Please enter unique empid. The empid %d has already been entered\n",e[*cntr].empid);
			return;
		}	
		printf("Enter the name:- ");
		while(getchar()!='\n');
		gets(e[*cntr].name);
		printf("Enter the salary:- ");
		scanf("%f",&e[*cntr].sal);
		printf("Enter the age:- ");
		scanf("%d",&e[*cntr].age);
		(*cntr)++;
		printf("\nRecord added successfully\n");
	}
	else
	{
		printf("No more records can be added\n");
		return;
	}
}

void display(Emp e[],int cntr)
{
	int i;
	for(i=0;i<cntr;i++)
		printf("%3d %7d %10s %9.2f %10d\n",i+1,e[i].empid,e[i].name,e[i].sal,e[i].age);
}

int search(Emp e[],int id,int cntr)
{
	int i;
	for(i=0;i<cntr;i++)
	{
		if(e[i].empid==id)
			return i+1;
	}
	return 0;
}

int modify(Emp e[],int id,int cntr)
{
	int i;
	for(i=0;i<cntr;i++)
	{
		if(e[i].empid==id)
		{
			printf("Enter the new details for empid %d\n",id);
			printf("Enter the new Name:- ");
			while(getchar()!='\n');
			gets(e[i].name);
			printf("Enter the new Salary:- ");
			scanf("%f",&e[i].sal);
			printf("Enter the new age:- ");
			scanf("%d",&e[i].age);
			return i+1;
		}
	}
	return 0;
}

int deleterecord(Emp e[],int id,int *cntr)
{
	int i,j;
	for(i=0;i<*cntr;i++)
	{
		if(e[i].empid==id)
		{
			for(j=i;j<*cntr;j++)
				e[j]=e[j+1];
			(*cntr)--;
			return 1;
		}
	}
	return 0;
}

int validate(Emp e[],int cntr)
{
	int i=0;
	if(cntr==0)
		return 1;
	for(i=0;i<cntr;i++)
	{
		if(e[i].empid==e[cntr].empid || e[i].age<=0)
			return 0;
	}
	return 1;
}








