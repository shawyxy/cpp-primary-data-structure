#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HeapDataType;
typedef struct HP
{
	HeapDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestory(HP* php);
void HeapPop(HP* php);
void HeapPush(HP* php, HeapDataType x);
bool HeapEmpty(HP* php);
HeapDataType HeapTop(HP* php);
int HeapSize(HP* php);

void Swap(HeapDataType* e1, HeapDataType* e2);
void AdjustDown(HeapDataType* a, int size, int parent);
void AdjustUp(HeapDataType* a, int child);

void HeapPrint(HP* php);