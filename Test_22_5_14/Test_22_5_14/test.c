#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);
//	return 0;
//}
void print(int* arr)
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[3] = { 1,2,3 };
	print(arr);
	return 0;
}