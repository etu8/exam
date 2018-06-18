#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
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
	//words[counter-1][strlen(wo)]
	for(int i=0;i<counter;i++){
		for(int j=strlen(words[i]);j>=0;j--){
			if(!isdigit(words[i][j])){
				if(strlen(words[i])== j){
					if(isalpha(words[i][j]))
						printf(" ");
					else
						printf(" ");
				}
				else{
					if(isalpha(words[i][j]))
						printf("%c",toupper(words[i][j]));
					else
						printf("%c",toupper(words[i][j]));
				}
			}
		}
	}	
	return 0;
}