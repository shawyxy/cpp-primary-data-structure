#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void test1()
{
	SListNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPrint(s);//不要传地址啊啊啊啊!!

	SListPopBack(&s);
	SListPrint(s);

	SListPopFront(&s);
	SListPrint(s);
	SListDestroy(&s);
}

void test2()
{
	SListNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);
	SListPrint(s);

	SListEraseAfter(&s, 2);
	SListPrint(s);

	SListInsertAfter(&s, 2, 9);
	SListPrint(s);

	SListDestroy(&s);

}

int main()
{
	test2();
	return 0;
}