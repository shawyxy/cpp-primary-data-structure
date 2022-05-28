#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void STInit(ST* ps)
{
	ps->top = 0;
	ps->capacity = 0;
	ps->data = NULL;
	return ps;
}
void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->top = 0;
	ps->capacity = 0;
	ps->data = NULL;
}

void STPush(ST* ps, STDataType x) 
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * newCapacity);
		
		if (tmp == NULL)
		{
			printf("realloc failde\n");
			exit(-1);
		}
		ps->data = tmp;
		ps->capacity = newCapacity;
	}

	ps->data[ps->top] = x;
	ps->top++;
}
void STPop(ST* ps)
{
	assert(ps);

	assert(!isEmpty(ps));

	ps->top--;
}

bool isEmpty(ST* ps)
{
	return ps->top == 0;
}
int STSize(ST* ps)
{
	return ps->top;
}
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!isEmpty(ps));
	return ps->data[ps->top - 1];//top指向第一个元素的下一位
}