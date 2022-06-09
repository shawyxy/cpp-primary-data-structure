#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HeapDataType;


typedef struct Heap
{
	HeapDataType* a;
	int size;
	int capacity;
}HP;

void AdjustDown(HeapDataType* a, int size, int parent);
void AdjustUp(HeapDataType* a, int child);
void Swap(HeapDataType* e1, HeapDataType* e2);

void HeapPush(HP* php, HeapDataType x);
void HeapPop(HP* php);


HeapDataType HeapTop(HP* php);
void HeapInit(HP* php);
void HeapDestory(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);
void HeapPrint(HP* php);