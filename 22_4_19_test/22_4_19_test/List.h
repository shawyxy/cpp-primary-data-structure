#pragma once
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType val;
}ListNode;

struct ListNode* ListNodeInit();
struct ListNode* CreatListNode(LTDataType x);
void ListNodeInsert(LTDataType x, struct ListNode* pos, int Pos);
void ListNodeErase(struct ListNode* pos, int Pos);
void ListNodePrint(struct ListNode* plist);
struct ListNode* ListNodeFind(struct ListNode* plist, int pos);