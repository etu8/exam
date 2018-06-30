#include<stdlib.h>
#include"fun.h"

int count(stack* massimo)
{
    return massimo->size;
}

stack* initializationofstack()
{
    stack* massimo = (stack*)malloc(sizeof(stack));
    massimo->size =0;
	return massimo;
}

int pop(stack* massimo)
{
    massimo->size--;
    return massimo->i[massimo->size];
}

void push(stack* massimo, int c)
{
	massimo->i[massimo->size] = c;
    massimo->size++;
}
