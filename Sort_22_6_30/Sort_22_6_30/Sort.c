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
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;
		//or j<-[1, n - i)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				Swap(&(a[j + 1]), &(a[j]));
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin;
	int right = end;
	int keyi = left;
	//int midi = GetMidIndex(a, begin, end);
	//Swap(&(a[midi]), &(a[keyi]));

	while (left < right)
	{
		//右找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//左找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//左右只要有一个停下来就交换
		Swap(&(a[right]), &(a[left]));
	}
	//最后左右相遇,将此处的数和key交换
	Swap(&(a[left]), &(a[keyi]));
	//将key的下标更新
	keyi = left;
	return keyi;
}

void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin;
	int right = end;
	int keyi = left;
	int midi = GetMidIndex(a, begin, end);
	Swap(&(a[midi]), &(a[keyi]));

	while (left < right)
	{
		//右找小
 		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//左找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//左右只要有一个停下来就交换
		Swap(&(a[right]), &(a[left]));
	}
	//最后左右相遇,将此处的数和key交换
	Swap(&(a[left]), &(a[keyi]));
	//将key的下标更新
	keyi = left;
	//分治:[begin, keyi - 1 ] keyi [keyi + 1, end]
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi + 1, end);
}
// 快速排序挖坑法
int PartSort2(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin;
	int right = end;
	int piti = begin;
	//int midi = GetMidIndex(a, begin, end);
	int key = a[piti];
	//Swap(&(a[midi]), &key);

	while (begin < end)
	{
		while (begin < end && key <= a[end])
		{
			end--;
		}
		//填坑
		a[piti] = a[end];
		piti = end;//更新坑的下标

		while (begin < end && key >= a[begin])
		{
			begin++;
		}
		//填坑
		a[piti] = a[begin];
		piti = begin;//更新坑的下标
	}
	//相遇,填坑
	a[piti] = key;
	return piti;
}

void QuickSort2(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	
	int left = begin;
	int right = end;
	int piti = begin;
	int midi = GetMidIndex(a, begin, end);
	int key = a[piti];
	Swap(&(a[midi]), &key);

	while (begin < end)
	{
		while (begin < end && key <= a[end])
		{
			end--;
		}
		//填坑
 		a[piti] = a[end];
		piti = end;//更新坑的下标

		while (begin < end && key >= a[begin])
		{
			begin++;
		}
		//填坑
		a[piti] = a[begin];
		piti = begin;//更新坑的下标
	}
	//相遇,填坑
	a[piti] = key;
	//传入的是当前栈帧中的区间,之前要保存一下
	QuickSort2(a, left, piti - 1);
	QuickSort2(a, piti + 1, right);
}
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;
	//int midi = GetMidIndex(a, begin, end);
	//Swap(&(a[midi]), &(a[keyi]));
	while (cur <= end)
	{
		//if(a[cur] < a[keyi] && prev++ != cur)
		if (a[cur] < a[keyi])
		{
			prev++;
			if (prev != cur)
			{
				Swap(&(a[cur]), &(a[prev]));
			}
		}
		cur++;
	}

	Swap(&(a[keyi]), &(a[prev]));
	keyi = prev;
	return keyi;
}

void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int prev = begin;
	int cur = prev + 1;
	int keyi = begin;
	int midi = GetMidIndex(a, begin, end);
	Swap(&(a[midi]), &(a[keyi]));
	while (cur <= end)
	{
		if (a[cur] < a[keyi])
		{
			prev++;
			if (prev != cur)
			{
				Swap(&(a[cur]), &(a[prev]));
			}
		}
		cur++;
	}

	Swap(&(a[keyi]), &(a[prev]));
	keyi = prev;

	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);

	StackPush(&st, end);
	StackPush(&st, begin);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);

		//keyi左边区间大于1
		if (keyi - left > 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}

		//keyi右边区间大于1
		if (right - keyi > 1)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}
	}
	StackDestory(&st);
}
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
	assert(a);

	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else // (a[begin] >= a[mid])
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}
