#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
//初始化链表,新增一个哨兵位节点
struct ListNode* ListNodeInit()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//只有一个哨兵位节点，让它两个指针指向自己
	head->next = head;
	head->prev = head;
	return head;
}
//创建新节点
struct ListNode* CreatListNode(LTDataType x)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->val = x;
	return newnode;
}

//在任意位置插入新节点
void ListNodeInsert(LTDataType x, struct ListNode* pos, int Pos)
{
	assert(pos);
	pos = ListNodeFind(pos, Pos);
	struct ListNode* newnode = CreatListNode(x);
	struct ListNode* prev = pos->prev;
	//链接
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
}
//删除任意位置的节点
void ListNodeErase(struct ListNode* pos, int Pos)
{
	assert(pos);
	pos = ListNodeFind(pos, Pos);

	struct ListNode* prev = pos->prev;
	struct ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
}
void ListNodePrint(struct ListNode* plist)
{
	assert(plist);

	struct ListNode* cur = plist->next;

	while (cur != plist)//有效节点不等于哨兵位节点
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
//查找函数，被插入和删除函数调用
struct ListNode* ListNodeFind(struct ListNode* plist, int pos)
{
	if (pos < 0)
		return -1;
	assert(plist);

	int count = 0;
	struct ListNode* cur = plist->next;
	while (cur != plist && count < pos)
	{
		count++;
		cur = cur->next;
	}
	return cur;
}