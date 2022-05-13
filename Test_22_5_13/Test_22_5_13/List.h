#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LSTDataType;

typedef struct LSTNode
{
	LSTDataType data;
	struct LSTNode* prev;
	struct LSTNode* next;
}LSTNode;

LSTNode* LSTNodeInit();
LSTNode* CreateNode(LSTDataType x);
void LSTNodeInsert(LSTNode* pos, LSTDataType x);
void LSTNodeErase(LSTNode* pos);
void LSTNodePushBack(LSTNode* phead, LSTDataType x);
void LSTNodePushFront(LSTNode* phead, LSTDataType x);
void LSTNodePopBack(LSTNode* phead);
void LSTNodePopFront(LSTNode* phead);
void LSTNodePrint(LSTNode* phead);
