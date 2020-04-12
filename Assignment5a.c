/*
 ============================================================================
 Class:- SE 10
 Batch:- H 10
 Roll no:- 23260
 Name:- Tanmay Pardeshi
 Assignment title:- Command Line Arguments
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE *fptr,*source,*target;
	char ch;
	if(argc>=3)
	{
		if(argc==3 && (strcmp(argv[1],"type"))==0)
		{
			fptr=fopen(argv[2],"r");
			if(fptr==NULL)
			{
				printf("File %s does not exist",argv[2]);
				return EXIT_SUCCESS;
			}
			ch=fgetc(fptr);
			while(!feof(fptr))
			{
				printf("%c",ch);
				ch=fgetc(fptr);
			}
			fclose(fptr);
		}
		if(argc==4 && (strcmp(argv[1],"copy"))==0)
		{
			source=fopen(argv[2],"r");
			target=fopen(argv[3],"w");
			if(source==NULL)
			{
				printf("File %s does not exist",argv[2]);
				return EXIT_SUCCESS;
			}
			ch=getc(source);
			while(!feof(source))
			{
				fputc(ch,target);
				ch=getc(source);
			}
			printf("File Has Been Copied Successfully!");
			fclose(source);
			fclose(target);
		}
	}
	return EXIT_SUCCESS;
}
