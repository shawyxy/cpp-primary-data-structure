#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


//void Test1()
//{
//	struct ListNode*  s = ListNodeInit();
//	ListNodeInsert(1, s);
//	ListNodeInsert(2, s);
//
//	ListNodeInsert(3, s);
//	ListNodeInsert(4, s);
//	ListNodeInsert(5, s);
//	ListNodeInsert(6, s);
//	ListNodePrint(s);
//
//	struct ListNode* pos = ListNodeFind(s, 5);
//	ListNodeErase(pos);
//	ListNodePrint(s);
//
//}

void Test2()
{
	struct ListNode* s = ListNodeInit();
	ListNodeInsert(1, s, 0);
	ListNodeInsert(2, s, 0);
	ListNodeInsert(3, s, 0);
	ListNodeInsert(4, s, 0);
	ListNodeInsert(5, s, 0);
	ListNodePrint(s);

	ListNodeInsert(5, s, 3);
	ListNodePrint(s);
	
	ListNodeErase(s, 0);
	ListNodeErase(s, 0);
	ListNodePrint(s);

}

int main()
{
	Test2();
	return 0;
}
