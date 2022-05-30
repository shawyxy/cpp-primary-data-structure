#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QueueDataType;

typedef struct QNode
{
	QueueDataType data;
	struct QNode* next;
}QNode;
typedef struct QNode QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QueueDataType x);
void QueuePop(Queue* pq);
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);