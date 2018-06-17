#include <stdio.h>
#include <string.h>
int main(){
char str[100];
int i=0;
fgets(str,100, stdin);
for(i=0;i<strlen(str)-1;i++){
	if(i%2==0)
		printf("%c", str[i]);
	}
	for(i=0;i<strlen(str)-1;i++){
	if(i%2!=0)
		printf("%c", str[i]);
	}
	return 0;
}