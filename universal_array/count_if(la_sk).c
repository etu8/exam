#include <stdio.h>
#include <stdlib.h>

#define N 20

int count_if(void* base, int num, int size, int (*pred)(const void*)) {
    int count = 0;
    for(int i=0; i<num; i++) {
        if(pred(base + i*size))
            count++;
    }
    return count;
}

int compar_int(const void * a) {
    if(*(int*) a != 0 && *(int*) a % 2 == 0)
        return 1;
    else
        return 0;
}

int compar_double(const void * a) {
    int x = *(double*)a;
    if(*(double*) a - (double)x == 0){
        return compar_int(&x);
    }
    else
        return 0;
}

int main()
{
    int arr_size;
    scanf("%d", &arr_size);

    int count = 0;
    void* arr;
    switch(arr_size) {
    case sizeof(int):
        arr = malloc(sizeof(int) * N);

        for(int i=0; i<N; i++)
            scanf("%d", arr + i*sizeof(int));

        count = count_if(arr, N, sizeof(int), compar_int);

        break;

    case sizeof(double):
        arr = malloc(sizeof(double) * N);

        for(int i=0; i<N; i++)
            scanf("%lf", arr + i*sizeof(double));

        count = count_if(arr, N, sizeof(double), compar_double);

        break;
    }
    printf("%d", count);
    free(arr);
    return 0;
}
