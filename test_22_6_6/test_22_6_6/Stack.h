#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackDataType;

typedef struct ST
{
	StackDataType* a;
	int size;
	int capacity;
}ST;

void StackInit(ST* pst);
void StackDestory(ST* pst);
void StackPop(ST* pst);
void StackPush(ST* pst, StackDataType x);
StackDataType StackTop(ST* pst);
bool StackEmpty(ST* pst);
int StackSize(ST* pst);