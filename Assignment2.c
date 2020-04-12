/*
 =========================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- Operations on matrices
 =========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define R 20
#define C 20

void accept(int [R][C],int [R][C],int *,int *,int *,int *);
void display(int [R][C],int ,int);
int add(int a[R][C],int b[R][C],int c[R][C], int ,int ,int ,int );
int multiply(int a[R][C],int b[R][C],int c[R][C], int ,int ,int ,int );
void transpose(int [R][C],int,int);
int saddlepoint(int [R][C],int,int);
void acceptp(int *,int *, int *,int *,int *,int *);
void displayp(int *,int ,int);
int addp(int *,int *,int *, int ,int ,int ,int );
int multiplyp(int *,int *,int *, int ,int ,int ,int );
void transposep(int *,int ,int);
int saddlepointp(int *,int,int);



int main(void)
{
	int a[R][C],b[R][C],c[R][C];
	int ar,ac,br,bc;
	int choice;
	int no;

	while(1)
	{
		printf("\nOperations on matrices\n");
		printf("1. Accept matrices\n");
		printf("2. Addition of two matrices\n");
		printf("3. Multiplication of two matrices\n");
		printf("4. Transpose of a matrix\n");
		printf("5. Saddle point of a matrix\n");
		printf("6. Accept matrices using pointers\n");
		printf("7. Addition of two matrices using pointers\n");
		printf("8. Multiplication of two matrices using pointers\n");
		printf("9. Transpose of a matrix using pointers\n");
		printf("10. Saddle point of a matrix using pointers\n");
		printf("11. Exit\n");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				accept(a,b,&ar,&ac,&br,&bc);
				break;
			case 2:
				display(a,ar,ac);
				display(b,br,bc);
				no=add(a,b,c,ar,ac,br,bc);
				//display C
				if(no==1)
				{
					printf("\nResultant Matrix is:- \n");
					display(c,ar,ac);
				}
				else
				{
					printf("\nAddition not possible\n");
					printf("Please enter the same order for A and B\n");
				}
				break;

			case 3:
				display(a,ar,ac);
				display(b,br,bc);
				no=multiply(a,b,c,ar,ac,br,bc);
				//display C
				if(no==1)
				{
					printf("\nResultant Matrix is:- \n");
					display(c,ar,bc);
				}
				else
				{
					printf("\nMultiplication not possible\n");
					printf("Please enter the same number of columns for A and number of rows for B\n");
				}
				break;


			case 4:
				display(a,ar,ac);
				printf("\nTranspose of matrix is:- \n");
				transpose(a,ar,ac);
				display(b,br,bc);
				printf("\nTranspose of matrix is:- \n");
				transpose(b,br,bc);
				break;
			case 5:
				display(a,ar,ac);
				choice=saddlepoint(a,ar,ac);
				if(choice)
					printf("\nSaddle point of matrix is:- %d\n",choice);
				else
					printf("\nNo saddle point found\n");
				display(b,br,bc);
				choice=saddlepoint(b,br,bc);
				if(choice)
					printf("\nSaddle point of matrix is:- %d\n",choice);
				else
					printf("\nNo saddle point found\n");
				break;

			case 6:
				acceptp(&a[0][0],&b[0][0],&ar,&ac,&br,&bc);
				break;
			case 7:
				displayp(&a[0][0],ar,ac);
				displayp(&b[0][0],br,bc);
				no=addp(&a[0][0],&b[0][0],&c[0][0],ar,ac,br,bc);
				if(no==1)
				{
					printf("Addition using pointers is:- \n");
					displayp(&c[0][0],ar,ac);
				}
				else
				{
					printf("\nAddition not possible.\n");
					printf("Please Enter same order for A and B\n");
				}
				break;

			case 8:
				displayp(&a[0][0],ar,ac);
				displayp(&b[0][0],br,bc);
				no=multiplyp(&a[0][0],&b[0][0],&c[0][0],ar,ac,br,bc);
				if(no)
				{
					printf("Multiplication using pointers is:- \n");
					displayp(&c[0][0],ar,bc);
				}
				else
				{
					printf("\nMultiplication not possible.\n");
					printf("Please Enter same number of columns for A and rows for B\n");
				}
				break;
			case 9:
				displayp(&a[0][0],ar,ac);
				printf("\nTranspose of matrix using pointers is:- \n");
				transposep(&a[0][0],ar,ac);
				displayp(&b[0][0],br,bc);
				printf("\nTranspose of matrix using pointers is:- \n");
				transposep(&b[0][0],br,bc);
				break;

			case 10:
				displayp(&a[0][0],ar,ac);
				no=saddlepointp(&a[0][0],ar,ac);
				if(no)
					printf("\nSaddle point of matrix using pointers is:- %d\n",no);
				else
					printf("\nNo saddle point found\n");
				displayp(&b[0][0],br,bc);
				no=saddlepointp(&b[0][0],br,bc);
				if(no)
					printf("\nSaddle point of matrix  using pointers is:- %d\n",no);
				else
					printf("\nNo saddle point found\n");
				break;
			case 11:
				return EXIT_SUCCESS;
			default:
				printf("Error in choice,try again\n");
		}
	}
	return EXIT_SUCCESS;
}


void accept(int a[R][C],int b[R][C],int *ar,int *ac,int *br,int *bc)
{
	int i,j;

	//accept elements of A
	printf("Enter the number of rows in matrix A:- ");
	scanf("%d",ar);
	printf("Enter the number of columns in matrix A:- ");
	scanf("%d",ac);
	printf("Enter the elements in matrix:- ");
	for(i=0;i<*ar;i++)
	{
		for(j=0;j<*ac;j++)
			scanf("%d",&a[i][j]);
	}
	//accept elements of B
	printf("Enter the number of rows in matrix B:- ");
	scanf("%d",&*br);
	printf("Enter the number of columns in matrix B:- ");
	scanf("%d",&*bc);
	printf("Enter the elements in matrix:- ");
	for(i=0;i<*br;i++)
	{
		for(j=0;j<*bc;j++)
			scanf("%d",&b[i][j]);
	}
	printf("\nMatrices succesfully accepted\n");
}

void display(int c[R][C],int cr,int cc)
{
	int i,j;

	//display elements of A
	printf("\nElements of matrix are:- \n");
	for(i=0;i<cr;i++)
	{
		for(j=0;j<cc;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
}

int add(int a[R][C],int b[R][C],int c[R][C], int ar,int ac,int br,int bc)
{
	int i,j;

	//validation
	if(ar != br || ac != bc)
		return 0;

	for(i=0;i<ar;i++)
	{
		for(j=0;j<ac;j++)
			c[i][j]=a[i][j]+b[i][j];
	}
	return 1;
}

int multiply(int a[R][C],int b[R][C],int c[R][C], int ar,int ac,int br,int bc)
{
	int i,j,k;
	//validation
	if(ac!=br)
		return 0;

	for(i=0;i<ar;i++)
	{
		for(j=0;j<bc;j++)
		{
			c[i][j]=0;
			for(k=0;k<ac;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
	return 1;
}

void transpose(int a[R][C],int ar,int ac)
{
	int i,j;
	for(i=0;i<ac;i++)
	{
		for(j=0;j<ar;j++)
			printf("%d\t",a[j][i]);
		printf("\n");
	}

}

int saddlepoint(int a[R][C],int ar,int ac)
{
	int i,j,k,y1,y2,x1,x2;
	int min,max;
	for(i=0;i<ar;i++)
	{
		min=a[i][0];
		for(j=0;j<ac;j++)
		{
			if(a[i][j]<=min)
			{
				min=a[i][j];
				x1=i;
				y1=j;
			}
		}
		max=a[0][y1];
		for(k=0;k<ar;k++)
		{
			if(a[k][y1]>=max)
			{
				max=a[k][y1];
				x2=k;
				y2=y1;
			}
		}
	if(max==min && x1==x2 && y1==y2)
		return max;
	}
	return 0;
}

void acceptp(int *a,int *b,int *ar,int *ac,int *br,int *bc)
{
	int i,j;

	//accept elements of A
	printf("Enter the number of rows in matrix A:- ");
	scanf("%d",ar);
	printf("Enter the number of columns in matrix A:- ");
	scanf("%d",ac);
	printf("Enter the elements in matrix:- ");
	for(i=0;i<*ar;i++)
	{
		for(j=0;j<*ac;j++)
			scanf("%d",(a+i*(*ac)+j));
	}
	//accept elements of B
	printf("Enter the number of rows in matrix B:- ");
	scanf("%d",&*br);
	printf("Enter the number of columns in matrix B:- ");
	scanf("%d",&*bc);
	printf("Enter the elements in matrix:- ");
	for(i=0;i<*br;i++)
	{
		for(j=0;j<*bc;j++)
			scanf("%d",(b+i*(*bc)+j));
	}
	printf("\nMatrices succesfully accepted\n");
}

void displayp(int *c,int cr,int cc)
{
	int i,j;

	//display elements of A
	printf("Elements of matrix are:- \n");
	for(i=0;i<cr;i++)
	{
		for(j=0;j<cc;j++)
			printf("%d\t",*(c+i*cc+j));
		printf("\n");
	}
}

int addp(int *a,int *b,int *c, int ar,int ac,int br,int bc)
{
	int i,j;

	//validation
	if(ar != br || ac != bc)
		return 0;

	for(i=0;i<ar;i++)
	{
		for(j=0;j<ac;j++)
			*(c+i*ac+j)=*(a+i*ac+j) + *(b+i*ac+j);
	}
	return 1;
}

int multiplyp(int *a,int *b,int *c, int ar,int ac,int br,int bc)
{
	int i,j,k;
	//validation
	if(ac!=br)
		return 0;
	for(i=0;i<ar;i++)
	{
		for(j=0;j<bc;j++)
		{
			*(c+i*bc+j)=0;
			for(k=0;k<ac;k++)
				*(c+i*bc+j) += *(a+i*ac+k) * *(b+k*bc+j);
		}
	}
	return 1;
}

void transposep(int *c,int cr,int cc)
{
	int i,j;
	for(j=0;j<cc;j++)
	{
		for(i=0;i<cr;i++)
			printf("%d\t",*(c+i*cc+j));
		printf("\n");
	}
}

int saddlepointp(int *c,int cr,int cc)
{
	int i,j,k,y1,y2,x1,x2;
	int min,max;
	for(i=0;i<cr;i++)
	{
		min=*(c+i*cc+0);
		for(j=0;j<cc;j++)
		{
			if(*(c+i*cc+j)<=min)
			{
				min=*(c+i*cc+j);
				x1=i;
				y1=j;
			}
		}
		max=*(c+0*cc+y1);
		for(k=0;k<cr;k++)
		{
			if(*(c+k*cc+y1)>=max)
			{
				max=*(c+k*cc+y1);
				x2=k;
				y2=y1;
			}
		}
	if(max==min && x1==x2 && y1==y2)
		return max;
	}
	return 0;
}
