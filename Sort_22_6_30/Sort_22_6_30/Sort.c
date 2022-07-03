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
void AdjustDwon(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}


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
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	//递归子区间，让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	
	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];

		}
	}
	//处理剩余数据
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//将tmp的内容回写
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;
	/*while (gap < n)
	{*/
		printf("gap=%d->", gap);
		for (int i = 0; i < n; i += gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = end1 + 1, end2 = end1 + gap;
			int j = begin1;
			int range = end2 - begin1 + 1;
			printf("[%d,%d] [%d, %d]--", begin1, end1, begin2, end2);
			while (begin1 <= end1 && begin2 <= end2)
			{
				//归并
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
				//处理剩余数据
				while (begin1 <= end1)
				{
					tmp[j++] = a[begin1++];
				}
				while (begin2 <= end2)
				{
					tmp[j++] = a[begin2++];
				}
			}
			memcpy(a + begin1, tmp + begin1, range * sizeof(int));
		}

		gap *= 2;
	//}

	free(tmp);
}
// 计数排序
void CountSort(int* a, int n)
{
	//求最值，得到范围
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];

		if (min > a[i])
			min = a[i];
	}
	int range = max - min + 1;

	int* tmp = (int*)malloc(range * sizeof(int));
	//检查
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//置零
	memset(tmp, 0, range * sizeof(int));
	//计数
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	//回写
	for (int i = 0; i < range; i++)
	{
		int j = 0;
		while (tmp[i])
		{
			a[j++] = i + min;
			tmp[i]--;
		}
	}
}
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
