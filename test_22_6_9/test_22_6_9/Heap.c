#include "Heap.h"
void AdjustDown(HeapDataType* a, int size, int parent)
{
	//Ĭ��������С
	int child = parent * 2 + 1;
	
	//��ֹ����:child�±�Խ��ʱ
	while (child < size)
	{
		//���Һ��ӱ����Ӹ�С,�����child
		if (a[child + 1] < a[child])
		{
			child++;
		}
		//������ӱȸ��׸�С,�򽻻�
		//�ǵ������Һ��ӵ��±�
		if (child + 1 < size && a[child] < a[parent])
		{	//ÿ�ν�����Ҫ����(ֻ�н�����ŵ���)
			//����Ϊʲô?
			//����ע��˳��
			Swap(&(a[child]), &(a[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else//ע����������break
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
		//���ϵ�����Ҫ�Ƚ����Һ�����?
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
	//β��Ҫ��if����
	php->a[php->size] = x;
	php->size++;
	//���ϵ���
	AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	//��������βԪ�ص�λ��
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	//ɾ����β��Ԫ��
	php->size--;
	//�ӶѶ���ʼ���µ���
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