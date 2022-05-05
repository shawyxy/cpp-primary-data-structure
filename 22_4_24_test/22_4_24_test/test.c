#define _CRT_SECURE_NO_WARNINGS 1
#include "SQList.h"

void test1()
{
	SQList s;
	SQListInit(&s);
	SQListPushBack(&s, 1);
	SQListPushBack(&s, 2);
	SQListPushBack(&s, 3);
	SQListPushBack(&s, 4);
	SQListPrint(&s);

	SQListPushfront(&s, 5);
	SQListPrint(&s);

	SQListPopBack(&s);
	SQListPopBack(&s);
	SQListPopBack(&s);
	SQListPrint(&s);



	SQListDestroy(&s);
}

int main()
{
	test1();
	return 0;
}