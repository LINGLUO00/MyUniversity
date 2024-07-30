#include"Stack.h"

void Init(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;

}

void Push(Stack* ps,int x)
{
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* tmp = (int*)realloc(ps->a, sizeof(int) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top++] = x;
}


void Pop(Stack* ps)
{
	assert(ps);
	assert(!Empty(ps));
	ps->top--;
}