/*
 ============================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- Sparse Matrix Operations
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define R 50
#define C 50

typedef struct s
{
	int row,column,value;
}Sparse;

void accept(int [R][C],int *,int *,int *,Sparse []);
void display(Sparse [],int );
void convert(int [R][C],int,int,int,Sparse []);
void add(Sparse [],Sparse [],Sparse [],int);
void transpose(Sparse [],Sparse []);
void fast(Sparse [],Sparse []);
void matrixform(Sparse [],int [R][C]);


int main(void)
{
	int choice;
	int mat1[R][C],mat2[R][C];
	int r1,c1,r2,c2;
	int count1,count2;
	Sparse s1[R],s2[R],s3[R];

	while(1)
	{
		printf("Sparse Matrix Operations\n");
		printf("1. Accept matrix and convert into sparse matrix\n");
		printf("2. Display matrix\n");
		printf("3. Addition of sparse matrix\n");
		printf("4. Simple transpose of sparse matrix\n");
		printf("5. Fast transpose of sparse matrix\n");
		printf("6. Convert sparse matrix into simple matrix\n");
		printf("7. Exit\n");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter matrix 1:- \n");
				accept(mat1,&r1,&c1,&count1,s1);
				printf("Enter matrix 2:- \n");
				accept(mat2,&r2,&c2,&count2,s2);
				break;

			case 2:
				printf("Sparse representation of matrix 1 is:- \n");
				display(s1,count1);
				printf("Sparse representation of matrix 2 is:- \n");
				display(s2,count2);
				break;

			case 3:
				if(r1==r2 && c1==c2)
				{
					printf("\nMatrix 1 is:- \n");
					display(s1,count1);
					printf("\nMatrix 2 is:- \n");
					display(s2,count2);
					add(s1,s2,s3,count1);
					printf("\nAddition of matrices is:- \n");
					display(s3,s3[0].value);
				}
				else
					printf("\nAddition not possible! Please enter the same order for 1 and 2\n\n");
				break;

			case 4:
				printf("Sparse representation of matrix 1 is:- \n");
				display(s1,count1);
				printf("Simple transpose of matrix 1 is:- \n");
				transpose(s1,s3);
				display(s3,count1);
				printf("Sparse representation of matrix 2 is:- \n");
				display(s2,count2);
				printf("Simple transpose of matrix 2 is:- \n");
				transpose(s2,s3);
				display(s3,count2);
				break;

			case 5:
				printf("Sparse representation of matrix 1 is:- \n");
				display(s1,count1);
				printf("Fast transpose of matrix 1 is:- \n");
				fast(s1,s3);
				display(s3,count1);
				printf("Sparse representation of matrix 2 is:- \n");
				display(s2,count2);
				printf("Fast transpose of matrix 2 is:- \n");
				fast(s2,s3);
				display(s3,count2);
				break;
			case 6:
				printf("Matrix form of matrix 1 is:- \n");
				matrixform(s1,mat1);
				printf("Matrix form of matrix 2 is:- \n");
				matrixform(s2,mat2);
				break;

			case 7:
				return EXIT_SUCCESS;

			default:
				printf("Error in choice,try again\n\n");
		}
	}
	return EXIT_SUCCESS;
}

void accept(int mat[R][C],int *r,int *c,int *count, Sparse s[R])
{
	int i,j;
	*count =1;
	printf("Enter number of rows in the matrix:- ");
	scanf("%d",r);
	printf("Enter number of columns in the matrix:- ");
	scanf("%d",c);
	for(i=0;i<*r;i++)
	{
		for(j=0;j<*c;j++)
		{
			printf("Enter element [%d][%d]:- ",i,j);
			scanf("%d",&mat[i][j]);
			if(mat[i][j]!=0)
				(*count)++;
		}
	}
	convert(mat,*r,*c,*count,s);
}

void convert(int mat[R][C],int r,int c,int count, Sparse s[R])
{
	int i,j,k;
	s[0].row=r;
	s[0].column=c;
	s[0].value=count-1;
	k=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(mat[i][j]!=0)
			{
				s[k].row=i;
				s[k].column=j;
				s[k].value=mat[i][j];
				k++;
			}
		}
	}
}

void display(Sparse s[R],int count)
{
	int i;
	printf("--------------------------------------------\n");
	printf("Index\tRow\tColumn\tValue\n");
	printf("--------------------------------------------\n");
	for(i=0;i<count;i++)
		printf("%d\t%d\t%d\t%d\n",i,s[i].row,s[i].column,s[i].value);
	printf("--------------------------------------------\n");
}

void add(Sparse s1[R],Sparse s2[R],Sparse s3[R],int count)
{
	int i=1,j=1,k=1;
	while(i<=s1[0].value && j<=s2[0].value)
	{
		if(s1[i].row==s2[j].row && s1[i].column == s2[j].column)
		{
			s3[k].row=s1[i].row;
			s3[k].column=s1[i].column;
			s3[k].value=s1[i].value + s2[j].value;
			i++,j++,k++;
		}
		else if(s1[i].row==s2[j].row && s1[i].column < s2[j].column)
		{
			s3[k].row=s1[i].row;
			s3[k].column=s1[i].column;
			s3[k].value=s1[i].value;
			i++,k++;
		}
		else if(s1[i].row==s2[j].row && s1[i].column > s2[j].column)
		{
			s3[k]=s2[j];
			j++,k++;
		}
		else if(s1[i].row < s2[j].row)
		{
			s3[k]=s1[i];
			i++,k++;
		}
		else if(s1[i].row > s2[j].row)
		{
			s3[k]=s2[j];
			j++,k++;
		}
	}
	while(i<=s1[0].value)
	{
		s3[k]=s1[i];
		i++,k++;
	}
	while(j<=s2[0].value)
	{
		s3[k]=s2[j];
		j++,k++;
	}
	s3[0].row=s1[0].row;
	s3[0].column=s1[0].column;
	s3[0].value=k;
}

void transpose(Sparse s[R],Sparse t[R])
{
	int cntr,i,j;
	t[0].row=s[0].column;
	t[0].column=s[0].row;
	t[0].value=s[0].value;
	if(s[0].value>0)
	{
		cntr=1;
		for(i=0;i<s[0].column;i++)
			for(j=1;j<=s[0].value;j++)
				if(s[j].column==i)
				{
					t[cntr].row=s[j].column;
					t[cntr].column=s[j].row;
					t[cntr].value=s[j].value;
					cntr++;
				}
	}
}

void fast(Sparse s[R], Sparse t[R])\
{
	int row_terms[R],start_pos[R];
	int i,j;
	t[0].row=s[0].column;
	t[0].column=s[0].row;
	t[0].value=s[0].value;

	if(s[0].value>0)
	{
		for(i=0;i<s[0].column;i++)
			row_terms[i]=0;

		for(i=1;i<=s[0].value;i++)
			row_terms[s[i].column]++;

		start_pos[0]=1;

		for(i=1;i<s[0].column;i++)
			start_pos[i]=start_pos[i-1]+row_terms[i-1];

		for(i=1;i<=s[0].value;i++)
		{
			j=start_pos[s[i].column]++;
			t[j].row=s[i].column;
			t[j].column=s[i].row;
			t[j].value=s[i].value;
		}
	}
}

void matrixform(Sparse s[R],int mat[R][C])
{
	int row,column;
	int i,j,cntr;
	row = s[0].row;
	column = s[0].column;

	cntr=1;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			if(s[cntr].row == i && s[cntr].column == j)
			{
				mat[i][j] = s[cntr].value;
				cntr++;
			}
			else
				mat[i][j]=0;
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}


