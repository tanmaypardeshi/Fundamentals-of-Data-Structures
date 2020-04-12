/*
 ============================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- String Operations
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stringlen(char []);
int palindrome(char []);
int stringcmp(char [],char []);
void stringcpy(char [],char []);
void revstring(char [],char []);
int substring(char [],char []);

int stringlenp(char *);
int palindromep(char *);
int stringcmpp(char *,char *);
void stringcpyp(char *,char *);
void revstringp(char *,char *);
int substringp(char *,char *);


int main(void)
{
	char str1[SIZE],str2[SIZE],str3[SIZE];
	int choice,no;

	printf("Enter a string:- ");
	gets(str1);

	while(1)
	{
		printf("\nString Operations\n");
		printf("1. Length of string\n");
		printf("2. Palindrome\n");
		printf("3. String Comparison\n");
		printf("4. Copy String\n");
		printf("5. Reverse String\n");
		printf("6. Check Substring\n");
		printf("7. Length of string using pointers\n");
		printf("8. Palindrome using pointers\n");
		printf("9. String Comparison using pointers\n");
		printf("10. Copy String using pointers\n");
		printf("11. Reverse String using pointers\n");
		printf("12. Check substring using pointers\n");
		printf("13. Exit");
		printf("\nEnter your choice:- ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nThe string entered is %s\n",str1);
				printf("Length of the given string is %d\n\n",stringlen(str1));
				break;
			case 2:
				printf("\nThe string entered is %s\n",str1);
				no=palindrome(str1);
				if(no==1)
					printf("The given string is a palindrome\n\n");
				else
					printf("The given string is not a palindrome\n\n");
				break;
			case 3:
				printf("\nEnter the string to be compared:- ");
				while(getchar()!='\n');
				gets(str2);
				printf("\nSource string:- %s\n",str1);
				printf("Target string:- %s\n",str2);
				if(stringcmp(str1,str2))
					printf("Both the strings are equal\n");
				else
					printf("Both the strings are not equal\n");
				break;
			case 4:
				printf("Enter source string:- ");
				while(getchar()!='\n');
				gets(str2);
				stringcpy(str3,str2);
				printf("\nString copied successfully\n");
				printf("Source string is:- %s\n",str2);
				printf("Copied string is:- %s\n",str3);
				break;
			case 5:
				revstring(str1,str2);
				printf("String reversed successfully\n");
				printf("Source string is:- %s\n",str1);
				printf("Reversed string is:- %s\n",str2);
				break;
			case 6:
				printf("Enter a string to check substring:- ");
				while(getchar()!='\n');
				gets(str2);
				no=substring(str1,str2);
				if(no==0)
					printf("\nNo substring found in original string\n");
				else
					printf("Substring %s found in source string %s %d number of times\n",str2,str1,no);
				break;
			case 7:
				printf("\nThe string entered is %s\n",str1);
				printf("Length of the given string is %d\n\n",stringlen(&str1[0]));
				break;
			case 8:
				printf("\nThe string entered is %s\n",str1);
				no=palindrome(&str1[0]);
				if(no==1)
					printf("The given string is a palindrome\n\n");
				else
					printf("The given string is not a palindrome\n\n");
				break;
			case 9:
				printf("\nEnter the string to be compared:- ");
				while(getchar()!='\n');
				gets(str2);
				printf("\nSource string:- %s\n",str1);
				printf("Target string:- %s\n",str2);
				if(stringcmp(&str1[0],&str2[0]))
					printf("Both the strings are equal\n");
				else
					printf("Both the strings are not equal\n");
				break;
			case 10:
				printf("Enter source string:- ");
				while(getchar()!='\n');
				gets(str2);
				stringcpy(&str3[0],&str2[0]);
				printf("\nString copied successfully\n");
				printf("Source string is:- %s\n",str2);
				printf("Copied string is:- %s\n",str3);
				break;
			case 11:
				revstringp(&str1[0],&str2[0]);
				printf("String reversed successfully\n");
				printf("Source string is:- %s\n",str1);
				printf("Reversed string is:- %s\n",str2);
				break;
			case 12:
				printf("Enter a string to check substring:- ");
				while(getchar()!='\n');
				gets(str2);
				no=substring(&str1[0],&str2[0]);
				if(no==0)
					printf("\nNo substring found in original string\n");
				else
					printf("Substring %s found in source string %s %d number of times\n",str2,str1,no);
				break;
			case 13:
				return EXIT_SUCCESS;

		}
	}
	return EXIT_SUCCESS;
}

int stringlen(char str1[])
{
	int i=0;
	while(str1[i]!='\0')
		i++;
	return i;
}

int palindrome(char str1[])
{
	int i,j;
	for(i=0,j=stringlen(str1)-1;i<=j;i++,j--)
	{
		if(str1[i]==str1[j])
			continue;
		else
			return 0;
	}
	return 1;

}

int stringcmp(char str2[],char str1[])
{
	int i,max=stringlen(str1);

	if(stringlen(str2)>stringlen(str1))
		max=stringlen(str2);

	for(i=0;i!=max;i++)
		if(str1[i]!=str2[i])
			return 0;
	return 1;

}

void stringcpy(char str3[],char str2[])
{
	int i=0;
	while(str2[i]!='\0')
	{
		str3[i]=str2[i];
		i++;
	}
	str3[i]='\0';
}

void revstring(char str1[],char str2[])
{
	int i=0,j;
	for(j=stringlen(str1)-1;j>=0;j--)
	{
		str2[i++]=str1[j];
	}
	str2[i]='\0';
}

int substring(char str1[],char str2[])
{
	char *ptr;
	char temp[SIZE];
	int i,j,cntr=0;
	for(i=0;str1[i]!='\0';i++)
	{
		ptr=&str1[i];
		for(j=0;j<stringlen(str2);j++)
		{
			temp[j]=*ptr;
			ptr++;
		}
		temp[j]='\0';
		if(stringcmp(temp,str2))
			cntr++;
	}
	if(cntr!=0)
		return cntr;

	return 0;
}

int stringlenp(char *str1)
{
	int i=0;
	while(*(str1+i)!='\0')
		i++;
	return i;
}

int palindromep(char *str1)
{
	int i,j;
	for(i=0,j=stringlen(str1)-1;i<=j;i++,j--)
	{
		if(*(str1+i)==*(str1+j))
			continue;
		else
			return 0;
	}
	return 1;

}

int stringcmpp(char *str2,char *str1)
{
	int i,max=stringlen(str1);

	if(stringlen(str2)>stringlen(str1))
		max=stringlen(str2);

	for(i=0;i!=max;i++)
		if(*(str1+i)!=*(str2+i))
			return 0;
	return 1;

}

void stringcpyp(char *str3,char *str2)
{
	int i=0;
	while(*(str2+i)!='\0')
	{
		*(str3+i)= *(str2+i);
		i++;
	}
	*(str3+i)='\0';
}

void revstringp(char *str1,char *str2)
{
	int i=0,j;
	for(j=stringlen(str1)-1;j>=0;j--)
	{
		*(str2+i)=*(str1+j);
		i++;
	}
	str2[i]='\0';
}

int substringp(char *str1,char *str2)
{
	char *ptr;
	char temp[SIZE];
	int i=0,j,cntr=0;
	for(i=0;*(str1+i)!='\0';i++)
	{
		ptr=(str1+i);
		for(j=0;j<stringlen(str2);j++)
		{
			*(temp+j)=*ptr;
			ptr++;
		}
		*(temp+j)='\0';
		if(stringcmp(temp,str2))
			cntr++;
	}
	if(cntr!=0)
		return cntr;

	return 0;
}


