#include "Sort.h"
/*
* 所有排序都为升序
*/


// 插入排序
//将区间[0，n]分为两部分
//将[0，end]看作有序，end+1是要插入的元素下标
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		//int tmpi = end + 1;//保存下标不可行
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])//原值大于要插入的数
			{
				a[end + 1] = a[end];//往后挪动
				end--;//向前比较
			}
			else
			{
				break;
			}
		}
		//循环终止（插入位置）有两种情况
		//此时end在空出来的前一个位置
		a[end + 1] = tmp;
	}
}
//// 希尔排序
//void ShellSort(int* a, int n)
//{
//	int gap = 3;
//	//保证不越界
//	for (int i = 0; i < n - gap; i += gap)
//	{
//		int end = i;
//		int tmp = a[end + gap];
//
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + gap] = a[end];
//				end -= gap;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + gap] = tmp;
//	}
//	InsertSort(a, n);
//}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}
// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{  
				mini = i;
			}
		}
		Swap(&(a[begin]), &(a[mini]));
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&(a[end]), &(a[maxi]));
		begin++;
		end--;
	}
}
// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n);
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);
//打印
void ArrayPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//交换函数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
