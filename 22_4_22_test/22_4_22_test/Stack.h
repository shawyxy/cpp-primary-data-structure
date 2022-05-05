#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int bool;
//#define TRUE 1;
//#define FALSE 0;

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
};

typedef struct Stack Stack;


//初始化栈
void StackInit(Stack* pst);
//销毁栈
void StackDestroy(Stack* pst);
//压栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);
//获取栈顶元素
STDataType StackTop(Stack* pst);
//获取栈的元素个数
int StackSize(Stack* pst);
//判断栈是否为空
bool StackEmpty(Stack* pst);
//打印
void StackPrint(Stack* pst);