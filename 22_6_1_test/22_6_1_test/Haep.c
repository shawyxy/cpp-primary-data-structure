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
void HeapPush(HP* php, HeapDataType x)
{
	assert(php);
	//扩容
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		//更新数组，容量
		php->a = tmp;
		php->capacity = newcapacity;
	}
	//尾插和更新计数器(注意顺序)
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	//将首尾元素交换
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;

	AdjustDown(php->a, php->size, 0);

}
HeapDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->a);

	return php->a[0];
}
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->a == NULL;
}
int HeapSize(HP* php)
{
	assert(php);

	return php->size - 1;
}

void AdjustDown(HeapDataType* a, int size, int parent)
{

	//默认左孩子是最小的
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
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
			//迭代要在交换后
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void Swap(HeapDataType* e1, HeapDataType* e2)
{
	HeapDataType* tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}
void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}