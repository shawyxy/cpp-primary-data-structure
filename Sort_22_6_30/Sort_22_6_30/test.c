#include "Sort.h"

void SortTest()
{
	int a1[10] = { 9,8,7,6,5,4,3,2,1,0 };
	InsertSort(a1, sizeof(a1) / sizeof(a1[0]));
	ArrayPrint(a1, sizeof(a1) / sizeof(a1[0]));
	
	int a2[10] = { 9,8,7,6,5,4,3,2,1,0 };
	ShellSort(a2, sizeof(a2) / sizeof(a2[0]));
	ArrayPrint(a2, sizeof(a2) / sizeof(a2[0]));
	

	int a3[10] = { 9,8,7,6,5,4,3,2,1,0 };
	SelectSort(a3, sizeof(a3) / sizeof(a3[0]));
	ArrayPrint(a3, sizeof(a3) / sizeof(a3[0]));
}
int main()
{
	SortTest();
	return 0;
}