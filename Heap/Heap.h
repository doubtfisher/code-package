#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;
void HeapInit(Heap* pHeap);
void HeapCreate(Heap* pHeap, HPDataType* a, int n);
void HeapDestroy(Heap* pHeap);

void HeapPush(Heap* pHeap, HPDataType x);
void HeapPop(Heap* pHeap);

HPDataType HeapTop(Heap* pHeap);
int HeapSize(Heap* pHeap);
int HeapEmpty(Heap* pHeap);

void HeapSort(Heap* pHeap);//∂—≈≈–Ú
void HeapPrint(Heap* pHeap);
