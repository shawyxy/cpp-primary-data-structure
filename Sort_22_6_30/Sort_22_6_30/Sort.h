#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"
// 插入排序
void InsertSort(int* a, int n); 
// 希尔排序
void ShellSort(int* a, int n); 
// 选择排序
void SelectSort(int* a, int n);
// 堆排序
void AdjustDwon(int* a, int n, int root); 
void HeapSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n);
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int begin, int end);
void QuickSort1(int* a, int begin, int end);
// 快速排序挖坑法
int PartSort2(int* a, int begin, int end);
void QuickSort2(int* a, int begin, int end);
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end);
void QuickSort3(int* a, int begin, int end);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);
// 打印
void ArrayPrint(int* a, int n);
// 交换函数
void Swap(int* a, int* b);
// 三数取中
int GetMidIndex(int* a, int begin, int end);