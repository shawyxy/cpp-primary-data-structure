#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

LSTNode* LSTNodeInit()
{
	LSTNode* head = CreateNode(0);
	head->next = head;
	head->prev = head;

	return head;
}
LSTNode* CreateNode(LSTDataType x)
{
	LSTNode* newnode = (LSTNode*)malloc(sizeof(LSTNode));
	if (newnode == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
void LSTNodeInsert(LSTNode* pos, LSTDataType x)
{
	assert(pos);

	LSTNode* newnode = CreateNode(x);
	LSTNode* prev = pos->prev;

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
void LSTNodeErase(LSTNode* pos)
{
	assert(pos);

	LSTNode* prev = pos->prev;
	LSTNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	
	free(pos);
}
void LSTNodePushBack(LSTNode* phead, LSTDataType x)
{
	assert(phead);
	LSTNodeInsert(phead, x);
}
void LSTNodePushFront(LSTNode* phead, LSTDataType x)
{
	assert(phead);

	LSTNodeInsert(phead->next, x);
}
void LSTNodePopBack(LSTNode* phead)
{
	assert(phead);
	assert(phead != phead->next);

	LSTNodeErase(phead->prev);
}
void LSTNodePopFront(LSTNode* phead)
{
	assert(phead);
	assert(phead != phead->next);

	LSTNodeErase(phead->next);
}
void LSTNodePrint(LSTNode* phead)
{
	assert(phead);

	LSTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
