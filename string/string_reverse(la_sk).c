#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 24

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

    for(int i=strlen(str)-1; i>=0; i--) {
        if(str[i] != '1')
            printf("%c", str[i]);
    }

    return 0;
}
