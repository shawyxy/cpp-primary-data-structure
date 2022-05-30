#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QueueDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)//һ���ڵ㶼û��
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else//����һ���ڵ�
	{
		pq->tail->next = newnode;//����
		pq->tail = newnode;//����
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QNode* next = pq->head->next;

	free(pq->head);
	pq->head = next;
}
QueueDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}
QueueDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}
 bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
}