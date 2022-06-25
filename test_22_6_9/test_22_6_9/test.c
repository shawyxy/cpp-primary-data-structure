#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include  <time.h>

void test1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
}
void ArrayPrint(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a);

}
void PrintTopK(int* a, int n, int k)
{
	//开辟k个长度的数组
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		KMinHeap[i] = a[i];
	}
	//用前k个元素建堆

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(KMinHeap, k, i);
	}
	//将剩下的k-1个元素和堆顶元素比较,比堆顶大则替换
	for (int j = k; j < n; j++)
	{
		//记得要跟堆顶元素比较
		if (a[j] > KMinHeap[0])
		{
			KMinHeap[0] = a[j];
			AdjustDown(KMinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", KMinHeap[i]);
	}

	printf("\n");
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}
	a[171] = 1000000 + 1;
	a[202] = 1000000 + 2;
	a[373] = 1000000 + 3;
	a[4499] = 1000000 + 4;
	a[55] = 1000000 + 5;
	a[676] = 1000000 + 6;
	a[7997] = 1000000 + 7;
	a[888] = 1000000 + 8;
	a[999] = 1000000 + 9;
	
	PrintTopK(a, n, 10);
}
int main()
{
	TestHeapSort();
	//TestTopk();
	return 0;
}