#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

int main()
{
    char* str = (char*) malloc(sizeof(char)*N);
    fgets(str, N, stdin);

    for(unsigned int i=0; i<strlen(str); i++) {
        if(isdigit(str[i]))
            str[i] = '1';
        else if(islower(str[i]))
            str[i] = toupper(str[i]);
    }

    int i = 0;
    char** words = (char**) malloc(sizeof(char*)*N);
    words[i] = strtok(str, " \n");
    while(words[i] != NULL) {
        i++;
        words[i] = strtok(NULL, " \n");
    }

    char temp_ch;
    for(int j=0; j<i; j++) {
        for(unsigned int k=0; k<strlen(words[j])/2; k++) {
            temp_ch = words[j][k];
            words[j][k] = words[j][strlen(words[j])- k - 1];
            words[j][strlen(words[j])- k - 1] = temp_ch;
        }
    }

    char* res = (char*) malloc(sizeof(char)*N);
    for(int j=0; j<i; j++) {
        strcat(res, " ");
        strcat(res, words[j]);
    }

    for(unsigned int j=1; j<strlen(res); j++) {
        if(res[j] != '1')
            printf("%c", res[j]);
    }

    return 0;
}
