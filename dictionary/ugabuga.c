#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 20
#define STRSIZE 100

typedef struct Dictionary {
    char word[20];
    char translation[20];
}Dictionary;

int main()
{
    Dictionary* arr = (Dictionary*) malloc(sizeof(Dictionary)*N);
    char* stop = (char*) malloc(sizeof(char)*N);
    scanf("%s ", stop);
    int i = 0;
    int size = N;
    while(strcmp(stop, "ugabuga")) {
        strcpy(arr[i].word, stop);
        scanf("%s", stop);
        strcpy(arr[i].translation, stop);
        scanf("%s ", stop);
        i++;
        if(i == N) {
            arr = (Dictionary*) realloc(arr, sizeof(Dictionary)*size*2);
            size *= 2;
        }
    }
    char* str = (char*) malloc(sizeof(char)*STRSIZE);
    fgets(str, STRSIZE, stdin);

    int j = 0;
    char** words = (char**) malloc(sizeof(char*)*STRSIZE);
    words[0] = strtok(str, " ");
    while(words[j] != NULL){
        j++;
        words[j] = strtok(NULL, " ");
    }
    words[j-1][strlen(words[j-1])-1] = 0;


    for(int x=0; x<j; x++){
        for(unsigned int z=0; z<strlen(words[x]); z++){
            if(isupper(words[x][z])) {
                words[x][z] = tolower(words[x][z]);
            }
        }
    }

    char* cur = (char*) malloc(sizeof(char)*STRSIZE);
    strcpy(cur, "<unknown>");
    for(int k=0; k<j; k++) {
        for(int y=0; y<i; y++) {
            if(!strcmp(arr[y].word, words[k])) {
                strcpy(cur, arr[y].translation);
            }
        }
        printf("%s ", cur);
        strcpy(cur, "<unknown>");
    }
    return 0;
}
