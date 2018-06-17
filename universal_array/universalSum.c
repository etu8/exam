#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 20

int compare_char(const void* a){
    return *(const char*)a;
}

int compare_int(const void * a) {
    return *(const int*)a;
}

int compare_double(const void * a) {
  return *(const double*)a;

}

size_t universalSum(const void * base, size_t num, size_t size, int(*cmp)(const void *)) {
    const char * pbase = (const char *)base;
    int i;
    int sum=0;
    for (i = 0; i < num; ++i)
        sum+=cmp(pbase+i*size);
    return sum;
}

int main() {
    size_t size;
    scanf("%zd", &size);

    int (*compare)(const void *);
    void * array;
    char * format_string;
    switch (size) {
    case 1:
        array = malloc(N * sizeof(char));
        format_string = " %c";
        compare = compare_char;
        break;
    case 4:
        array = malloc(N * sizeof(int));
        format_string = " %d";
        compare = compare_int;
        break;
    case 8:
        array = malloc(N * sizeof(double));
        format_string = " %lf";
        compare = compare_double;
        break;
    }
    for (int i = 0; i < N; ++i)
        scanf(format_string, array + i * size);
    printf("%zd", universalSum(array, N, size, compare));
    return 0;
}
