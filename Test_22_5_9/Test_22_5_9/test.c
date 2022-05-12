#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	int k = 0;
	int son = 1;
	int mother = 1;
	scanf("%d %d", &n, & k);

	//·ÖÄ¸
	for (int i = 1; i <= k; i++)
	{
		mother *= i;
	}

	//·Ö×Ó
	for (int i = n; i >= n - k + 1; i--)
	{
		son *= i;
	}

	printf("%d\n", son / mother);
	return 0;
}