#include <stdio.h>
#include <stdlib.h>

#define N 20

void add_int(void* a, const void* b) {
    *(int*)a = *(int*)a + *(int*)b;
}

void add_char(void* a, const void* b) {
    *(int*)a = *(int*)a + *(char*)b;
}

void universalSum(void* base, size_t num, size_t size, void* init, void (*add)(void*, const void*)) {

    for(unsigned int i=1; i<num; i++) {

        add(init, base + i*size);
    }

}

int main()
{
    int size;
    scanf("%d", &size);

    void* arr;
    void* res = malloc(sizeof(int));
//    *(int*)res = 0;
    switch(size) {
    case 1:
        arr = (char*) malloc(sizeof(char)*N);
        for(int i=0; i<N; i++) {
            scanf(" %c", &(((char*)arr)[i]));
        }
        *(int*)res = ((char*)arr)[0];
        universalSum(arr, N, size, res, add_char);
        break;
    case 4:
        arr = malloc(sizeof(int)*N);
        for(int i=0; i<N; i++) {
            scanf("%d", &(((int*)arr)[i]));
        }
        *(int*)res = ((int*)arr)[0];
        universalSum(arr, N, size, res, add_int);
        break;
    }

    printf("%d", *((int*)res));
    return 0;
}
