#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SQDataType;

typedef struct SQList
{
	SQDataType* a;//数组
	int size;//元素个数
	int capacity;//容量
}SQList;

void SQListInit(SQList* ps); 
void SQListDestroy(SQList* ps);

void SQListInsert(SQList* ps, int pos, SQDataType x);
void SQListErase(SQList* ps, int pos);

void SQListPushBack(SQList* ps, SQDataType x);
void SQListPushfront(SQList* ps, SQDataType x);
void SQListPopBack(SQList* ps);
void SQListPopFront(SQList* ps);

void SQListCapacityCheck(SQList* ps);
int SQListFind(SQList* ps, SQDataType x);
void SQListPrint(SQList* ps);