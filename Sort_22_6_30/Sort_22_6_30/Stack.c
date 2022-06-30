#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"


void StackInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	pst->size = 0;
}
void StackDestory(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->capacity = 0;
	pst->size = 0;
}
void StackPop(ST* pst)
{
	assert(pst);
	if (pst->size == 0)
		return;

	pst->size--;
}
void StackPush(ST* pst, StackDataType x)
{
	assert(pst);

	if (pst->capacity == pst->size)
	{
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		StackDataType* tmp = (StackDataType*)realloc(pst->a, sizeof(StackDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		pst->a = tmp;
	}
	pst->a[pst->size] = x;
	pst->size++;
}
StackDataType StackTop(ST* pst)
{
	assert(pst);
	if (pst->size == 0)
		return;

	return pst->a[pst->size - 1];
}
bool StackEmpty(ST* pst)
{
	assert(pst);

	return pst->size == 0;
}
int StackSize(ST* pst)
{
	assert(pst);

	return pst->size;
}