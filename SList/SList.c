#include "SList.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
	plist->_tail = NULL;
}

void SListDestroy(SList* plist)
{
	SListNode* cur;
	assert(plist);
	cur = plist->_head;
	while (cur)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = plist->_tail = NULL;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	return node;
}

void SListPushBack(SList* plist, SLTDataType x)
{
	SListNode* tail;
	assert(plist);
	//1.一个节点没有
	//2.一个以上节点
	/*if (plist->_tail == NULL)
	{
		plist->_head = plist->_tail = BuySListNode(x);
	}
	else
	{
		SListNode* newnode = BuySListNode(x);
		plist->_tail->_next = newnode;
		plist->_tail = newnode;
	}*/
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		tail = plist->_head;
		while (tail->_next)
		{
			tail = tail->_next;
		}
		tail->_next = BuySListNode(x);
	}
}

void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* prev, *tail;
	prev = NULL;
	tail = plist->_head;
	if (tail->_next == NULL)
	{
		free(tail);
		plist->_head = NULL;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)
{
	SListNode* newnode;
	assert(plist);
    newnode = BuySListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;

}

void SListPopFront(SList* plist)
{
	SListNode* next;
	assert(plist);
    next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data== x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return cur;
}

void SListInsertAfter(SList* plist,SListNode* pos, SLTDataType x)//在pos后面插入
{
	assert(pos);
	SListNode* next ,*newnode;
	next = pos->_next;
	newnode = BuySListNode(x);
	newnode->_next = next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)//删除pos后面的节点
{
	assert(pos);
	SListNode* next;
	if (pos->_next == NULL)
	{
		return;
	}
		next = pos->_next->_next;
		free(pos->_next);
		pos->_next = next;
}

void SListRemove(SList* plist, SLTDataType x)//删除某个给定的数
{
	assert(plist);
	if (plist->_head->_data == x)
	{
		SListPopFront(plist);
		return;
	}
	SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d-> ", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}