#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
	SListNode* _tail;
}SList;

void SListInit(SList* plist);
void SListDestroy(SList* plist);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);

void SListInsertAfter(SList* plist, SListNode* pos, SLTDataType x);//在pos后面插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);

