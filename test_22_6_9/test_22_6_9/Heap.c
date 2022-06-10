#include "Heap.h"
void AdjustDown(HeapDataType* a, int size, int parent)
{
	//默认左孩子最小
	int child = parent * 2 + 1;
	
	//终止条件:child下标越界时
	while (child < size)
	{
		//若右孩子比左孩子更小,则更新child
		if (a[child + 1] < a[child])
		{
			child++;
		}
		//如果孩子比父亲更小,则交换
		//记得限制右孩子的下标
		if (child + 1 < size && a[child] < a[parent])
		{	//每次交换后都要迭代(只有交换后才迭代)
			//想想为什么?
			//迭代注意顺序
			Swap(&(a[child]), &(a[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else//注意这个巧妙的break
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
		//向上调整需要比较左右孩子吗?
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
void Swap(HeapDataType* e1, HeapDataType* e2)
{
	HeapDataType tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void HeapPush(HP* php, HeapDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	//尾插要在if外面
	php->a[php->size] = x;
	php->size++;
	//向上调整
	AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	//交换堆首尾元素的位置
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	//删除堆尾的元素
	php->size--;
	//从堆顶开始向下调整
	AdjustDown(php->a, php->size, 0);
}


HeapDataType HeapTop(HP* php)
{
	assert(php);

	return php->a[0];
}
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
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
int HeapSize(HP* php)
{
	assert(php);

	return php->size;
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