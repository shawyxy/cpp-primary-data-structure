//
// Created by 肖越 on 2022/5/28.
//
#pragma once
#ifndef TEST1_22_5_28_QUEUE_H
#define TEST1_22_5_28_QUEUE_H

#endif //TEST1_22_5_28_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QueueDataType;

typedef struct QueueNode
{
    struct QueueNode* next;
    QueueDataType data;
}QNode;

typedef struct Queue
{
    QNode * head;
    QNode * tail;//!
}Queue;


void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QueueDataType x);
void QueuePop(Queue* pq);
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
