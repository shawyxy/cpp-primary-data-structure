#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//
//	int n = 0, x = 0, y = 0;
//	int day = 0;
//
//	scanf("%d %d %d", &x, &y, &n);
//
//	int high = x, low = y;
//	while (n > 0)
//	{
//		n -= x;
//
//		if (n <= 0)
//		{
//			day++;
//			break;
//
//		}
//		n += y;
//		day++;
//
//	}
//	printf("%d", day);
//	return 0;
//}

#include <stdio.h>

//int main()
//{
//	int n = 0;
//	int x = 0;
//	while (~scanf("%d", &n))
//	{
//		x = n / 2;
//		if (x == 0)
//			continue;
//		printf("%d\n", x);
//	}
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int m = 0, t = 0;
	int a = 0, b = 0;
	int max = 0;
	int count = 0;
	scanf("%d %d", &m, &t);
	int* arr = (int*)malloc(sizeof(int) * (m + 1));

		while (t--)
		{
			scanf("%d %d", &a, &b);
			for (int i = 1; i <= m; i++)
			{
				arr[i] = 0;
			}
			for (int i = 1; i <= m; i++)
			{
				//统计数字出现的次数
				arr[a]++;
				arr[b]++;
			}

			
				if (arr[a] > 1 || arr[b] > 1)
				{
					count++;//有相同的元素为一组
					if (arr[a] == 1)
					{
						arr[a] = -1;
					}
					if (arr[b] == 1)
					{
						arr[b] = -1;
					}
				}
			
			for (int i = 1; i <= m; i++)
			{
				if (arr[i] > 1)
				{
					arr[i] = -1;
				}
			}
			if (arr[a] == 1 && arr[b] == 1)
			{
				count++;//单独一对
			}
			for (int i = 1; i <= m; i++)
			{
				if (arr[i] == 0)
				{
					count++;//单独一个
				}
			}
			
			for (int i = 1; i <= m; i++)
			{
				if (arr[i] == -1)
				{
					max++;
				}
			}
		}
	
	printf("%d %d", count, max);
	return 0;
}