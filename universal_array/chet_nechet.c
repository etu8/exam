#include<stdio.h>
#include<math.h>
#define NUM 5

int count_if(void* base, size_t num, size_t size, int (*pred)(const void*))
{
	int count = 0;
	for(int i = 0; i < num; i++)
	{
		if( pred(base+i*size) )
			count++;
	}
	return count;
}

int check_int(const void* c)
{
	int a = *(int*)c;
	return ~a&1;
}

int check_double(const void* d)
{	
	double b = *(double*)d;
	int a = b;
	if( a < b || a>b)
		return 0;
	return ~a&1;
}

int main()
{
	int size;
	scanf("%d", &size);
	if( size == 4)
	{
		int array[NUM];
		for(int i = 0; i<NUM; i++)
			scanf("%d", &array[i]);
		printf("%d\n",count_if(array, NUM, size, check_int));
		return 0;
	}
	else 
	{
		double array[NUM];
		for(int i = 0; i<NUM; i++)
			scanf("%lf", &array[i]);
		printf("%d\n",count_if(array, NUM, size, check_double));
		return 0;
	}
}
	
