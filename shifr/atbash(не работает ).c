
#include <stdio.h>
#include <stdlib.h>
#define M 26
typedef struct Pair
{
	int n;
	char c;
}Pair;

int main(){
	int i;
	int count =0;
	int num[7];
	char text[8];
	Pair* pairs=(Pair*)malloc(M*sizeof(Pair));
	for(i=0;i<M;i++){
		scanf("%d %c",&pairs[i].n, &pairs[i].c);
	}
	for(i=0;i<7;i++){
		scanf("%d",&num[i]);
	}
	int j, k = 0;
	for(i=0;i<7;i++){
		for(j=0;j<M;j++){
			if(num[i]==pairs[j].n){
				text[k]=pairs[j].c;
				count++;
			}
		}
		k++;
	}
	if(count<7){
		printf("Error\n");
		return 0;
	}
	else
		puts(text);
	return 0;
}
