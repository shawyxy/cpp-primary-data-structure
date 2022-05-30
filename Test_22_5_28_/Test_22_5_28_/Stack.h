#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct ST
{
	STDataType* data;//动态栈
	int top;//栈顶元素位置
	int capacity;//栈的容量
}ST;
typedef struct ST ST;

void STInit(ST* ps);
void STDestroy(ST* ps);

void STPush(ST* ps, STDataType x);
void STPop(ST* ps);

bool isEmpty(ST* ps);
int STSize(ST* ps);
STDataType STTop(ST* ps);