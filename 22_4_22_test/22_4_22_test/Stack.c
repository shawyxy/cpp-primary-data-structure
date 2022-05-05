#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"


//初始化栈
void StackInit(Stack* pst)
{
	assert(pst);

	pst->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->top = 0;
	pst->capacity = 4;
}
//销毁栈
void StackDestroy(Stack* pst)
{
	assert(pst);

	free(pst->data);
	pst->data = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
//压栈(相当于尾插)
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);

	//判断top是否达到容量，达到则扩容
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->data, sizeof(STDataType) * pst->capacity * 2);//扩容
		if (tmp == NULL)//增容失败
		{
			printf("realloc failed\n");
			exit(-1);//告诉系统这是异常终止程序
		}
		pst->data = tmp;
		pst->capacity = pst->capacity * 2;//更新容量
	}

	pst->data[pst->top] = x;//压入数据
	pst->top++;
}
//出栈(相当于尾删)
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}
//获取栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	return pst->data[pst->top - 1];//top指向第一个元素的下一位
}
//获取栈的元素个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;//top从0开始，其值等于元素个数
}
//判断栈是否为空
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;//top为0则为真，否则为假
}
//打印
void StackPrint(Stack* pst)
{
	assert(pst);

	for (int i = 0; i < pst->top; i++)
	{
		printf("%d ", pst->data[i]);
	}
}