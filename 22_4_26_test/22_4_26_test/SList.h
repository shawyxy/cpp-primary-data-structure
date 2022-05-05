#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pplist);
void SListDestroy(SListNode** pplist);

SListNode* SListNodeCreate(SListDataType x);

void SListPushBack(SListNode** pplist, SListDataType x);
void SListPushFront(SListNode** pplist, SListDataType x);

void SListPopBack(SListNode** pplist);
void SListPopFront(SListNode** pplist);

void SListInsertAfter(SListNode** pplist, int pos, SListDataType x);
void SListEraseAfter(SListNode** pplist, int pos);

SListNode* SListFind(SListNode* plist, int pos);
void SListPrint(SListNode* plist);
