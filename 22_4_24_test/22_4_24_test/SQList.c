#define _CRT_SECURE_NO_WARNINGS 1
#include "SQList.h"

void SQListInit(SQList* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SQListDestroy(SQList* ps)
{
	assert(ps);
	
	ps->capacity = 0;
	ps->size = 0;
	free(ps->a);
}

void SQListInsert(SQList* ps, int pos, SQDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size );

	SQListCapacityCheck(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SQListErase(SQList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	
	int end = pos + 1;
	while (end < ps->size)
	{
		ps->a[end - 1] = ps->a[end];
		end++;
	}
	ps->size--;
}

void SQListPushBack(SQList* ps, SQDataType x)
{
	assert(ps);

	SQListInsert(ps, ps->size, x);
}
void SQListPushfront(SQList* ps, SQDataType x)
{
	assert(ps);

	SQListInsert(ps, 0, x);
}
void SQListPopBack(SQList* ps)
{
	assert(ps);

	SQListErase(ps, ps->size - 1);
}
void SQListPopFront(SQList* ps)
{
	assert(ps);

	SQListErase(ps, 0);
}

void SQListCapacityCheck(SQList* ps)
{
	assert(ps);

	
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newCapacity* sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	
}
int SQListFind(SQList* ps, SQDataType x)
{
	assert(ps);
	
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SQListPrint(SQList* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}