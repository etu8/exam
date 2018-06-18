#include<stdio.h>

int func_count( int last)
{
	int a;
	scanf("%d", &a);
	if( last == 0 && a == 0)
		return 0;
	if(a == 1)
	return 1 + func_count( a);
	else
		return func_count(a);
}

int main()
{
	printf("%d\n", func_count(1));
	return 0;
}
