#include "Sort.h"
/*
* ��������Ϊ����
*/


// ��������
//������[0��n]��Ϊ������
//��[0��end]��������end+1��Ҫ�����Ԫ���±�
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		//int tmpi = end + 1;//�����±겻����
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])//ԭֵ����Ҫ�������
			{
				a[end + 1] = a[end];//����Ų��
				end--;//��ǰ�Ƚ�
			}
			else
			{
				break;
			}
		}
		//ѭ����ֹ������λ�ã����������
		//��ʱend�ڿճ�����ǰһ��λ��
		a[end + 1] = tmp;
	}
}
//// ϣ������
//void ShellSort(int* a, int n)
//{
//	int gap = 3;
//	//��֤��Խ��
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

// ϣ������
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
// ѡ������
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
// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// ð������
<<<<<<< HEAD
void BubbleSort(int* a, int n);
=======
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
>>>>>>> 22f2a112757dfa3f884d1ee5ffe2df31527cd752
// ��������ݹ�ʵ��
// ��������hoare�汾
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
		//����С
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//���Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//����ֻҪ��һ��ͣ�����ͽ���
		Swap(&(a[right]), &(a[left]));
	}
	//�����������,���˴�������key����
	Swap(&(a[left]), &(a[keyi]));
	//��key���±����
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
		//����С
 		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//���Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//����ֻҪ��һ��ͣ�����ͽ���
		Swap(&(a[right]), &(a[left]));
	}
	//�����������,���˴�������key����
	Swap(&(a[left]), &(a[keyi]));
	//��key���±����
	keyi = left;
	//����:[begin, keyi - 1 ] keyi [keyi + 1, end]
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi + 1, end);
}
// ���������ڿӷ�
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
		//���
		a[piti] = a[end];
		piti = end;//���¿ӵ��±�

		while (begin < end && key >= a[begin])
		{
			begin++;
		}
		//���
		a[piti] = a[begin];
		piti = begin;//���¿ӵ��±�
	}
	//����,���
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
		//���
 		a[piti] = a[end];
		piti = end;//���¿ӵ��±�

		while (begin < end && key >= a[begin])
		{
			begin++;
		}
		//���
		a[piti] = a[begin];
		piti = begin;//���¿ӵ��±�
	}
	//����,���
	a[piti] = key;
	//������ǵ�ǰջ֡�е�����,֮ǰҪ����һ��
	QuickSort2(a, left, piti - 1);
	QuickSort2(a, piti + 1, right);
}
// ��������ǰ��ָ�뷨
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
// �������� �ǵݹ�ʵ��
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

		//keyi����������1
		if (keyi - left > 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}

		//keyi�ұ��������1
		if (right - keyi > 1)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}
	}
	StackDestory(&st);
}
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);
//��ӡ
void ArrayPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��������
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
