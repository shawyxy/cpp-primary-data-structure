//
// Created by 肖越 on 2022/5/5.
//
#include<stdio.h>
int main()
{
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int mother = 1;//分母
    int son = 1;//分子
    for (int i = 1; i <= n - k + 1; ++i) {
        mother *= i;
    }
    for (int i = 1; i <= k ; ++i) {
        son *= i;
    }
    printf("%d\n", mother / son);
    return 0;
}

