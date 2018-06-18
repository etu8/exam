#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100
 
void main()
{
	int size = SIZE;
	char** word = (char**)malloc(SIZE*sizeof(char*));
	char** translation = (char**)malloc(SIZE*sizeof(char*));
	int i = 0, flag = 1,j;
	while(1)
	{
		if(i == size)
		{	
			size*=2;
			word = (char**)realloc(word, size*sizeof(char*));
			translation = (char**)realloc(translation, size*sizeof(char*));
		}
		word[i] = (char*)malloc(SIZE*sizeof(char));
		scanf("%s",word[i]);	
		if(strcmp(word[i], "ugabuga") == 0)
			break;
		translation[i] = (char*)malloc(SIZE*sizeof(char));
		scanf("%s", translation[i]);
		i++;
	}
	char* sent = (char*)malloc(100*sizeof(char));
	j = 0;
	fgetc(stdin);
	do
	{
		sent[j] = fgetc(stdin);
		if(sent[j] == '\n')
			break;
		sent[j] = tolower(sent[j]);
		j++;
	}while(1);
	char* tmp = strtok(sent, " \n");
	while(tmp != NULL)
	{
		for(j = 0; j<i;j++)
			if(strcmp(tmp, word[j]) == 0)
			{
				printf("%s ", translation[j]);
				break;
			}
		if(strcmp(tmp, word[j]))
			printf("<unknown> ");
		tmp = strtok(NULL, " \n");
	}
	printf("\n");
} 
