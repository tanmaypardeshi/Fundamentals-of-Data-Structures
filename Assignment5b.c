/*
 ============================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- File Handling
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
	int empid,age;
	char name[25];
	float sal;
}Emp;

void addrecord(Emp *);
void displayrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int validate(int );

int main(void)
{
	Emp e;
	int choice;

	while(1)
	{
		printf("Database Management System\n");
		printf("1. Add records\n");
		printf("2. Display records\n");
		printf("3. Modify records\n");
		printf("4. Delete a record\n");
		printf("5. Search a record\n");
		printf("6. Exit");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				addrecord(&e);
				break;
			case 2:
				displayrecord();
				break;
			case 3:
				modifyrecord();
				break;
			case 4:
				deleterecord();
				break;
			case 5:
				searchrecord();
				break;
			case 6:
				return EXIT_SUCCESS;
			default:
				printf("\nError in choice, try again\n\n");
		}
	}
	return EXIT_SUCCESS;
}

void addrecord(Emp *e)
{
	int flag,key;
	FILE *fptr1;
	fptr1=fopen("recs.txt","a");

	printf("Enter the Emp. ID:- ");
	scanf("%d",&e->empid);
	key=e->empid;
	flag=validate(key);
	if(flag==0)
	{
		printf("\nPlease enter unique empid\n\n");
		return;
	}
	printf("Enter the name:- ");
	while(getchar()!='\n');
	gets(e->name);
	printf("Enter the salary:- ");
	scanf("%f",&e->sal);
	printf("Enter the age:- ");
	scanf("%d",&e->age);
	fwrite(e,sizeof(*e),1,fptr1);
	fclose(fptr1);
	printf("\nRecord successfully stored\n\n");
}

void displayrecord()
{
	Emp e;
	int cntr=1;
	FILE *fptr1;
	fptr1=fopen("recs.txt","r");
	printf("---------------------------------------------------\n");
	printf("Sr.no\tEmp.ID\t  Name\t  Salary\t Age");
	printf("\n---------------------------------------------------\n");
	while(fread(&e,sizeof(e),1,fptr1))
	{
		printf("%3d %7d %10s %9.2f %10d\n",cntr,e.empid,e.name,e.sal,e.age);
		cntr++;
	}
	printf("---------------------------------------------------\n");
	fclose(fptr1);
}

void modifyrecord()
{
	Emp e;
	int id,flag;
	FILE *fptr1,*fptr2;
	fptr1=fopen("recs.txt","r+");
	fptr2=fopen("temp.txt","w");
	printf("\nEnter the empid to modify:- ");
	scanf("%d",&id);
	flag=0;
	while(fread(&e,sizeof(e),1,fptr1))
	{
		if(id==e.empid)
		{
			flag=1;
			printf("Enter changes:- \n");
			printf("Enter the name:- ");
			while(getchar()!='\n');
			gets(e.name);
			printf("Enter the salary:- ");
			scanf("%f",&e.sal);
			printf("Enter the age:- ");
			scanf("%d",&e.age);
			fwrite(&e,sizeof(e),1,fptr2);
		}
		else
			fwrite(&e,sizeof(e),1,fptr2);
	}
	remove("recs.txt");
	rename("temp.txt","recs.txt");
	if(!flag)
		printf("\nRecord with empid %d not found\n\n",id);
	else
		printf("\nRecord successfully modified\n\n");
	fclose(fptr1);
	fclose(fptr2);
}

void deleterecord()
{
	Emp e;
	int id,flag;
	FILE *fptr1,*fptr2;
	fptr1=fopen("recs.txt","r+");
	fptr2=fopen("temp.txt","w");
	printf("\nEnter the empid to delete:- ");
	scanf("%d",&id);
	flag=0;
	while(fread(&e,sizeof(e),1,fptr1))
	{
		if(id!=e.empid)
		{
			fwrite(&e,sizeof(e),1,fptr2);
		}
		else
		{
			flag=1;
			continue;
		}
	}
	remove("recs.txt");
	rename("temp.txt","recs.txt");
	if(!flag)
		printf("\nRecord with empid %d not found\n\n",id);
	else
		printf("\nRecord successfully deleted\n\n");
	fclose(fptr1);
	fclose(fptr2);
}

void searchrecord()
{
	Emp e;
	int flag,id;
	FILE *fptr1;
	fptr1=fopen("recs.txt","r");
	printf("Enter the empid to search:- ");
	scanf("%d",&id);
	flag=0;
	while(fread(&e,sizeof(e),1,fptr1))
	{
		if(e.empid==id)
		{
			flag=1;
			break;
		}
	}
	if(!flag)
		printf("\nRecord with empid %d not found\n\n",id);
	else
	{
		printf("\nRecord with empid %d found\n\n",id);
		printf("Details of the employee are:- \n\n");
		printf("Employee id:- %d",e.empid);
		printf("\nEmployee name:- %s",e.name);
		printf("\nEmployee salary:- %.2f",e.sal);
		printf("\nEmployee age:- %d\n\n ",e.age);
		fclose(fptr1);
	}
}

int validate(int key)
{
	Emp e;
	FILE *fptr1;
	fptr1=fopen("recs.txt","r");
	while(fread(&e,sizeof(e),1,fptr1))
	{
		if(e.empid==key)
			return 0;
	}
	return 1;	
}










