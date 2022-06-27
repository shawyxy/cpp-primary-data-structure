#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BinaryTree.h"
typedef struct BTNode* QueueDataType;
struct BTNode;
typedef struct QNode
{
	struct QNode* next;
	QueueDataType data;
}QNode;

//typedef int QueueDataType;
//typedef struct QNode
//{
//	struct QNode* next;
//	QueueDataType data;
//}QNode;

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
QueueDataType QueueTail(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);