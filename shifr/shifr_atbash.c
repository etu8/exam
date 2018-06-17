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
	int num[7];
	Pair* pairs=(Pair*)malloc(M*sizeof(Pair));
	for(i=0;i<M;i++){
		scanf("%d %c",&pairs[i].n, &pairs[i].c);
	}
	for(i=0;i<7;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<7;i++){
		for(int j=0;j<M;j++){
			if(num[i]==pairs[j].n)
				printf("%c",pairs[j].c);
			else
				printf("Error\n");
		}
	}
	return 0;
}