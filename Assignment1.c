/*
 ============================================================================
 Class: SE 10
 Batch:- H 10
 Roll Number:- 23260
 Name:- Tanmay Pardeshi
 Assignment Title:- Operations on sets
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE1 20
#define SIZE2 40

//fn declns

void accept(int [],int [],int *,int *);
void display(int [],int [],int , int);
int Union(int [],int [],int [], int ,int);
int Intersection(int [],int [],int [], int ,int);
int Difference(int[], int [], int [],int, int);


int main(void)
{
	int a[SIZE1],b[SIZE1],c[SIZE2],temp1[SIZE1],temp2[SIZE1];
	int no_a,no_b,no_c=0,no_d=0,no_e,i;
	int choice;

	while(1)
	{
			printf("\nOperations on sets\n");
			printf("1. Accept the sets\n");
			printf("2. Union of sets\n");
			printf("3. Intersection of sets\n");
			printf("4. Difference of sets\n");
			printf("5. Symmetric Difference of sets\n");
			printf("6. Exit the program\n\n");

			printf("Enter your choice:- ");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
					accept(a,b,&no_a,&no_b);
					break;

				case 2:
					no_c=Union(a,b,c,no_a,no_b);

					display(a,b,no_a,no_b);

					printf("Union of given sets is:- ");
					for(i=0;i<no_c;i++)
						printf("%d   ",c[i]);

					printf("\n\n");
					break;

				case 3:
					no_c=Intersection(a,b,c,no_a,no_b);

					display(a,b,no_a,no_b);

					printf("Intersection of given sets is:- ");
					for(i=0;i<no_c;i++)
						printf("%d   ",c[i]);

					printf("\n\n");
					break;

				case 4:

					display(a,b,no_a,no_b);

					no_c=Difference(a,b,c,no_a,no_b);
					printf("Difference A-B is:- ");
					for(i=0;i<no_c;i++)
						printf("%d   ",c[i]);
					printf("\n");

					no_d=Difference(b,a,c,no_a,no_b);

					printf("Difference B-A is:- ");
					for(i=0;i<no_d;i++)
						printf("%d   ",c[i]);

					printf("\n\n");
					break;

				case 5:
						display(a,b,no_a,no_b);

						no_c=Difference(a,b,temp1,no_a,no_b);
						no_d=Difference(b,a,temp2,no_a,no_b);
						no_e=Union(temp1,temp2,c,no_c,no_d);

						printf("Symmetric Difference of both sets is:- ");
						for(i=0;i<no_e;i++)
							printf("%d  ",c[i]);
						printf("\n\n");
						break;
				case 6:
					return EXIT_SUCCESS;
			}
	}

	return EXIT_SUCCESS;
}

void accept(int a[],int b[],int *no_a,int *no_b)
{
	int i,j;
	printf("Enter the no. of elements in set A:- ");
	scanf("%d",&*no_a);
	printf("Enter the elements in set A:- \n");

	for(i=0;i<*no_a;i++)
	{
			scanf("%d",&a[i]);
			for(j=0;j<i;j++)
			{
					if(a[i]==a[j])
					{
							printf("Please Re-enter non duplicate element\n");
							i--;
					}
			}
	}
	printf("Enter the no. of elements in set B:- ");
	scanf("%d",&*no_b);
	printf("Enter the elements in set B:- \n");
	for(i=0;i<*no_b;i++)
		{
				scanf("%d",&b[i]);
				for(j=0;j<i;j++)
				{
						if(b[i]==b[j])
						{
								printf("Please Re-enter non duplicate element\n");
								i--;
						}
				}
		}
}

void display(int a[],int b[],int no_a,int no_b)
{
	int i;
	printf("Given set A is:- ");
	for(i=0;i<no_a;i++)
		printf("%d\t",a[i]);

	printf("\n");

	printf("Given set B is:- ");
	for(i=0;i<no_b;i++)
		printf("%d\t",b[i]);

	printf("\n");
}

int Union(int a[],int b[],int c[],int no_a,int no_b)
{
		int i,j,k=0,flag=0;

		for(i=0;i<no_a;i++)
		{
			c[k]=a[i];
			k++;
		}
		for(i=0;i<no_b;i++)
		{
				flag=0;
				for(j=0;j<no_a;j++)
				{
					if(c[j]==b[i])
						flag=1;
				}
				if(!flag)
				{
						c[k]=b[i];
						k++;
				}
		}

		return k;
}

int Intersection(int a[],int b[],int c[],int no_a,int no_b)
{
		int i,j,k=0;
		for(i=0;i<no_a;i++)
		{
				for(j=0;j<no_b;j++)
				{
					if(a[i]==b[j])
					{
						c[k++]=a[i];
						break;
					}
				}

		}
		return k;
}


int Difference(int a[],int b[],int c[],int no_a,int no_b)
{
	int i,j,k=0,flag;
	for(i=0;i<no_a;i++)
	{
		flag=1;
		for(j=0;j<no_b;j++)
		{
			if(a[i]==b[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			c[k]=a[i];
			k++;
		}
	}
	return k;
}
