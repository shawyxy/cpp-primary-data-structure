#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


void SListDestroy(SListNode** pplist)
{
	assert(*pplist);
	SListNode* cur = *pplist;

	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	
}
SListNode* SListNodeCreate(SListDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBack(SListNode** pplist, SListDataType x)
{
	SListNode* newnode = SListNodeCreate(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* cur = *pplist;
		while (cur->next)//节点至少为1
		{
			cur = cur->next;//迭代找尾
		}

		cur->next = newnode;
	}
}
void SListPushFront(SListNode** pplist, SListDataType x)
{
	assert(*pplist);

	SListNode* next = (*pplist)->next;//保存下第二个节点

	*pplist = SListNodeCreate(x);
	(*pplist)->next = next;
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);

	SListNode* cur = *pplist;

	while (cur->next->next)//找尾节点的前一个节点
	{
		cur = cur->next;
	}

	free(cur->next);
	cur->next = NULL;
}
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);

	SListNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}

void SListInsertAfter(SListNode** pplist, int pos, SListDataType x)
{
	assert(*pplist);

	SListNode* newnode = SListNodeCreate(x);
	SListNode* ppos = SListFind(*pplist, pos);//要插入的前一个位置

	SListNode* next = ppos->next;//保存下一个节点
	ppos->next = newnode;
	newnode->next = next;

}
void SListEraseAfter(SListNode** pplist, int pos)
{
	assert(*pplist);

	SListNode* ppos = SListFind(*pplist, pos);//要删除的前一个位置
	if (ppos->next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = ppos->next->next;//保存要删除的位置下一个节点

		free(ppos->next);
		ppos->next = next;
	}

}

SListNode* SListFind(SListNode* plist, int pos)
{
	assert(plist);
	SListNode* cur = plist;
	while (--pos)
	{
		cur = cur->next;//找尾
	}

	return cur;
}
void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
