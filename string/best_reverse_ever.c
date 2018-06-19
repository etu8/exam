#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int i, j;
    char str[100];
    char words[100][100];
    int counter = 0;
    fgets(str, 100, stdin);
    str[strlen(str)-1]='\0';
    char* word=strtok(str, " ");
    while(word!=NULL){
        strcpy(*(words+counter), word);
        word=strtok(NULL, " ");
        counter++;
    }
	for (i = 0; i < counter; i++){
		for (j = strlen(words[i]); j >= 0; j --){
			if (!isdigit(words[i][j]))
				printf("%c", toupper(words[i][j]));
		}
		printf(" ");
	}
	return 0;
}
