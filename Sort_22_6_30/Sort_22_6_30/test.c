#include "Sort.h"
void QuickSortTest()
{
	int a1[] = { 9,8,7,6,5,4,3,2,1,0 };
	QuickSort1(a1, 0, (sizeof(a1) / sizeof(a1[0])) - 1);
	printf("QuickSort1->   ");
	ArrayPrint(a1, sizeof(a1) / sizeof(a1[0]));

	int a2[] = { 9,8,7,6,5,4,3,2,1,0 };
	QuickSort2(a2, 0, (sizeof(a2) / sizeof(a2[0])) - 1);
	printf("QuickSort2->   ");
	ArrayPrint(a2, sizeof(a2) / sizeof(a2[0]));


	int a3[] = {9,8,7,6,5,4,3,2,1,0};
	QuickSort3(a3, 0, sizeof(a3) / sizeof(a3[0]) - 1);
	printf("QuickSort3->   ");
	ArrayPrint(a3, sizeof(a3) / sizeof(a3[0]));

	int a4[] = { 9,8,7,6,5,4,3,2,1,0 };
	QuickSortNonR(a4, 0, sizeof(a4) / sizeof(a4[0]) - 1);
	printf("QuickSortNonR->");
	ArrayPrint(a4, sizeof(a4) / sizeof(a4[0]));
}

void MergeSortTest()
{
	int a1[] = { 9,8,7,6,5,4,3,2,1,0 };
	MergeSort(a1, sizeof(a1) / sizeof(a1[0]));
	printf("MergeSort->    ");
	ArrayPrint(a1, sizeof(a1) / sizeof(a1[0]));

	int a2[] = { 9,8,7,6,5,4,3,2,1,0 };
	MergeSortNonR(a2, sizeof(a2) / sizeof(a2[0]));
	printf("MergeSortNonR->");
	ArrayPrint(a2, sizeof(a2) / sizeof(a2[0]));
}


void SortTest()
{
	int a1[] = { 9,8,7,6,5,4,3,2,1,0 };
	printf("original array:");
	ArrayPrint(a1, sizeof(a1) / sizeof(a1[0]));
	printf("\n");
	InsertSort(a1, sizeof(a1) / sizeof(a1[0]));
	printf("InsertSort->   ");
	ArrayPrint(a1, sizeof(a1) / sizeof(a1[0]));
	
	int a2[] = { 9,8,7,6,5,4,3,2,1,0 };
	ShellSort(a2, sizeof(a2) / sizeof(a2[0]));
	printf("ShellSort->    ");
	ArrayPrint(a2, sizeof(a2) / sizeof(a2[0]));
	
	int a3[] = { 9,8,7,6,5,4,3,2,1,0 };
	SelectSort(a3, sizeof(a3) / sizeof(a3[0]));
	printf("SelectSort->   ");
	ArrayPrint(a3, sizeof(a3) / sizeof(a3[0]));
	
	int a4[] = { 9,8,7,6,5,4,3,2,1,0 };
	BubbleSort(a4, sizeof(a4) / sizeof(a4[0]));
	printf("BubbleSort->   ");
	ArrayPrint(a4, sizeof(a4) / sizeof(a4[0]));

	QuickSortTest();
	
	int a5[] = { 9,8,7,6,5,4,3,2,1,0 };
	HeapSort(a5, sizeof(a5) / sizeof(a5[0]));
	printf("HeapSort->     ");
	ArrayPrint(a5, sizeof(a5) / sizeof(a5[0]));

	int a6[] = { 9,8,7,6,5,4,3,2,1,0 };
	HeapSort(a6, sizeof(a6) / sizeof(a6[0]));
	printf("CountSort->    ");
	ArrayPrint(a6, sizeof(a6) / sizeof(a6[0]));

	MergeSortTest();

}

int main()
{
	SortTest();
	return 0;
}