
#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;//数组
	size_t _size;//有多少个数据
	size_t _capacity;//容量
}SeqList;

void CheckCapacity(SeqList* psl);//容量检测
void SeqListInit(SeqList* psl, size_t capacity);//初始化
void SeqListDestory(SeqList* psl);//销毁

void SeqListPushBack(SeqList* psl, SLDataType x);//尾上插入数据
void SeqListPopBack(SeqList* psl);//尾上删除数据
void PushFront(SeqList* psl,SLDataType x);//头部插入数据
void PopFront(SeqList* psl);//删除头部数据

int SeqListFind(SeqList* psl, SLDataType x);//O(N)//寻找某个指定的值
void SeqAt(SeqList* pSeq, size_t pos, SLDataType x);//替换指定位置的元素的值


void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//任何位置的插入数据
void SeqListErase(SeqList* psl, size_t pos);//删除某个位置的数据
void SeqListRemove(SeqList* psl,SLDataType x);//删除某个数值
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//修改某个位置的数据

void SeqListPrint(SeqList* psl);//打印顺序表
void TestSeqList();

void SeqListBubbleSort(SeqList* psl);
int BinarySearch(SeqList* psl, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);
void SelectSort(SeqList* psl);

#endif//__SEQLIST_H__