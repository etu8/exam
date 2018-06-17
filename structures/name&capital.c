#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Country {
	char name[30];
	unsigned int population;
	char capital[30];
};

int cmp (const void * a, const void * b)
{
    struct Country* A = (struct Country*)a;
    struct Country* B = (struct Country*)b;
    int i;
    if (strcmp(A->name, B->name)==0){
	for(i=0; i<sizeof(A->capital); i++){
		if (A->capital[i] > B->capital[i])
			return 1;
		if (A->capital[i] < B->capital[i])
			return -1;
	}
	return -1;
    } 
    for(i=0; i<sizeof(A->name); i++){
		if (A->name[i] > B->name[i])
			return 1;
		if (A->name[i] < B->name[i])
			return -1;
    }
    return -1;
}

int main(){
	int a;
	int i;
	scanf("%d", &a);
	struct Country arr[a];
   	for(int i=0;i<a;i++){
   	    scanf("%s", &arr[i].name);
   	    scanf("%u", &arr[i].population);
   	    scanf("%s", &arr[i].capital);
   	}
	
	qsort(arr, a, sizeof(struct Country), cmp);

	
	for (int i=0; i<a; i++)
	        printf("%s %u %s ", arr[i].name, arr[i].population, arr[i].capital);

return 0;
}
