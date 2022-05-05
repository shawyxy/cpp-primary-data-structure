#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	//0个元素，头尾指针置空
	pq->head = NULL;
	pq->tail = NULL;
}
//入队（尾插）
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//新增节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc  failed\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	
	if (pq->tail == NULL)//没有元素
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;//链接旧尾和新节点
		pq->tail = newnode;//更新尾
	}
}
//出队（头删）
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	if (pq->head->next == NULL)//只有一个节点
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;//保存头的下一个节点
		free(pq->head);
		pq->head = next;
	}

}
//获取队头的元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}
//获取队尾的元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}
//获取队列中元素的个数
int QueueSize(Queue* pq)
{
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}
//销毁
void QueueDestroy(Queue* pq)
{
	QNode* cur = pq->head;
	while (cur)//将每个节点都销毁 
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;//迭代
	}
	//头尾指针置空
	pq->head = NULL;
	pq->tail = NULL;
}
//打印
void QueuePrint(Queue* pq)
{
	assert(pq);

	Queue* cur = pq->head;
	while (cur)
	{
		printf("%d ", cur->head->data);
		cur = cur->head->next;
	}
}