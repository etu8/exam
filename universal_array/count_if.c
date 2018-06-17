#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 20
/*
int compare_char(const void a){

}
*/
int compare_int(const void * a) {
    if((*(const int *)a )%2!=0 && (*(const int *)a )%3==0)
      return 0;
    else
    return -1;
}

int compare_double(const void * a) {
  double val=(*(const double*)a);
  int intval=val;
  if(val>intval == intval>val)
    return compare_int(&intval);
  else
    return -1;
}

size_t count_if(const void * base, size_t num, size_t size, int(*cmp)(const void *)) {
    const char * pbase = (const char *)base;
    size_t counter = 0;
    int i;
    for (i = 0; i < num; ++i)
        if (cmp(pbase + i * size) == 0) 
            counter++;
    return counter;
}

int main() {
    size_t size;
    scanf("%zd", &size);

    int (*compare)(const void *);
    void * array;
    char * format_string;
    switch (size) {
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
    printf("%zd", count_if(array, N, size, compare));
    return 0;
}
