#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;
//用链表表示队列
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
};
typedef struct QueueNode QNode;

//队列结构
typedef struct Queue
{
	QNode* head;
	QNode* tail;
};
typedef struct Queue Queue;
//初始化
void QueueInit(Queue* pq);
//入队
void QueuePush(Queue* pq, QDataType x);
//出队
void QueuePop(Queue* pq);
//获取队头的元素
QDataType QueueFront(Queue* pq);
//获取队尾的元素
QDataType QueueBack(Queue* pq);
//获取队列中元素的个数
int QueueSize(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//打印
void QueuePrint(Queue* pq);
