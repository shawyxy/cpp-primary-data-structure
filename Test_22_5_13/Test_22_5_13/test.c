#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void test1()
{
	LSTNode* head = LSTNodeInit();
	LSTNodePushBack(head, 1);
	LSTNodePushBack(head, 2);
	LSTNodePushBack(head, 3);
	LSTNodePushBack(head, 4);
	LSTNodePushBack(head, 5);
	LSTNodePrint(head);

	LSTNodePopFront(head);
	LSTNodePrint(head);

	LSTNodePopBack(head);
	LSTNodePrint(head);


}

int main()
{
	test1();

	return 0;
}