#include "List.h"



ListTest()
{
	List lt;
	ListInit(&lt);

	ListPushBack(&lt,1);
	ListPushBack(&lt,2);
	ListPushBack(&lt,3);
	ListPushBack(&lt,4);
	ListPushBack(&lt,5);
	ListPopBack(&lt);
	ListPushFront(&lt, 0);
	ListPopFront(&lt);
	ListNode* pos = ListFind(&lt, 2);
	ListInsert(pos, 5);
	ListErase(pos);
	ListPrint(&lt);
	



}


int main()
{
	ListTest();
	system("pause");
	return 0;
}