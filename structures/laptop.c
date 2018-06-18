#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Laptop {
    char brand[30];
    char processor[30];
    unsigned int ram;
    double weight;
}Laptop;

int compar(const void* a, const void* b) {
    int i = strcmp((*(Laptop**)a)->brand, (*(Laptop**)b)->brand);
    if(i>0)
        return 1;
    else if(i<0)
        return 0;
    else {
        if((*(Laptop**)a)->weight >= (*(Laptop**)b)->weight)
            return 1;
        else
            return 0;
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    Laptop** arr = (Laptop**) malloc(sizeof(Laptop*)*num);
    for(int i=0; i<num; i++)
    {
        arr[i] = (Laptop*) malloc(sizeof(Laptop));
        scanf("%s %s %u %lf", arr[i]->brand, arr[i]->processor, &(arr[i]->ram), &(arr[i]->weight));
    }

    qsort(arr, num, sizeof(Laptop*), compar);

    for(int i=0; i<num; i++)
    {
        printf("%s %s %u %lf ", arr[i]->brand, arr[i]->processor, arr[i]->ram, arr[i]->weight);
        free(arr[i]);
    }
    free(arr);
    return 0;
}
