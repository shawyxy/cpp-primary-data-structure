#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void HeapDestory(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;

	AdjustDown(php->a, php->size, 0);
}
void HeapPush(HP* php, HeapDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(php->a, sizeof(HeapDataType)*newCapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		php->capacity = newCapacity;
		php->a = tmp;
	}
	php->size++;
	php->a[php->size - 1] = x;
	AdjustUp(php->a, php->size - 1);
}
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
HeapDataType HeapTop(HP* php)
{
	assert(php);

	return php->a[0];
}
int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

void Swap(HeapDataType* e1, HeapDataType* e2)
{
	HeapDataType tmp = 0;
	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}
void AdjustDown(HeapDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			Swap(&(a[child]), &(a[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&(a[child]), &(a[parent]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}



void HeapPrint(HP* php)
{
	assert(php);

	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}