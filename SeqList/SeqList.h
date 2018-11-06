
#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;//����
	size_t _size;//�ж��ٸ�����
	size_t _capacity;//����
}SeqList;

void CheckCapacity(SeqList* psl);//�������
void SeqListInit(SeqList* psl, size_t capacity);//��ʼ��
void SeqListDestory(SeqList* psl);//����

void SeqListPushBack(SeqList* psl, SLDataType x);//β�ϲ�������
void SeqListPopBack(SeqList* psl);//β��ɾ������
void PushFront(SeqList* psl,SLDataType x);//ͷ����������
void PopFront(SeqList* psl);//ɾ��ͷ������

int SeqListFind(SeqList* psl, SLDataType x);//O(N)//Ѱ��ĳ��ָ����ֵ
void SeqAt(SeqList* pSeq, size_t pos, SLDataType x);//�滻ָ��λ�õ�Ԫ�ص�ֵ


void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//�κ�λ�õĲ�������
void SeqListErase(SeqList* psl, size_t pos);//ɾ��ĳ��λ�õ�����
void SeqListRemove(SeqList* psl,SLDataType x);//ɾ��ĳ����ֵ
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//�޸�ĳ��λ�õ�����

void SeqListPrint(SeqList* psl);//��ӡ˳���
void TestSeqList();

void SeqListBubbleSort(SeqList* psl);
int BinarySearch(SeqList* psl, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);
void SelectSort(SeqList* psl);

#endif//__SEQLIST_H__