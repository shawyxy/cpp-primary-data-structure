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
void BubbleSort(int* a, int n);
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
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
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
