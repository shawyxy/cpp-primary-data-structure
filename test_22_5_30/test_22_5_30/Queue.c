#define _CRT_SECURE_NO_WARNINGS 1
//
// Created by ФԽ on 2022/5/28.
//

#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);

    pq->head == NULL;
    pq->tail == NULL;
}
void QueueDestroy(Queue* pq)
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
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;

    if (pq->tail == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }

}

void QueuePop(Queue* pq)
{
    assert(pq);

    assert(!QueueEmpty(pq));

    if (pq->head->next == NULL)//only one element
    {
        free(pq->head);
        pq->head = NULL;
        pq->tail = NULL;
    }
    else//exceed one element
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
}
QueueDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(QueueEmpty(pq));

    return pq->head->data;
}
QueueDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(QueueEmpty(pq));

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

    int size = 0;
    QNode* cur = pq->head;

    while (cur)
    {
        cur = cur->next;
        size++;
    }
    return size;
}

