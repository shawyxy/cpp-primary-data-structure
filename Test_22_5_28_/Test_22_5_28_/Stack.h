#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct ST
{
	STDataType* data;//��̬ջ
	int top;//ջ��Ԫ��λ��
	int capacity;//ջ������
}ST;
typedef struct ST ST;

void STInit(ST* ps);
void STDestroy(ST* ps);

void STPush(ST* ps, STDataType x);
void STPop(ST* ps);

bool isEmpty(ST* ps);
int STSize(ST* ps);
STDataType STTop(ST* ps);