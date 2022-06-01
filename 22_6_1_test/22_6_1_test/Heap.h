#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HeapDataType;

typedef struct HP
{
	HeapDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestory(HP* php);
void HeapPush(HP* php, HeapDataType x);
void HeapPop(HP* php);
HeapDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);

void AdjustDown(HeapDataType* a, int size, int parent);
void AdjustUp(HeapDataType* a, int child);
void Swap(HeapDataType* e1, HeapDataType* e2);
void HeapPrint(HP* php);
