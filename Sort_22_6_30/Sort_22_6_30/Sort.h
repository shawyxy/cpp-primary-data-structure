#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"
// ��������
void InsertSort(int* a, int n); 
// ϣ������
void ShellSort(int* a, int n); 
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDwon(int* a, int n, int root); 
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int begin, int end);
void QuickSort1(int* a, int begin, int end);
// ���������ڿӷ�
int PartSort2(int* a, int begin, int end);
void QuickSort2(int* a, int begin, int end);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end);
void QuickSort3(int* a, int begin, int end);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int begin, int end);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);
// ��ӡ
void ArrayPrint(int* a, int n);
// ��������
void Swap(int* a, int* b);
// ����ȡ��
int GetMidIndex(int* a, int begin, int end);