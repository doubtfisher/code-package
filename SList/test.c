#include "SList.h"



void TestSList()
{
	SList sl;
	SListInit(&sl);
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPushBack(&sl, 5);

	SListPopBack(&sl);

	SListPushFront(&sl, 0);

	SListPopFront(&sl);
	
	SListNode* pos = SListFind(&sl, 3);
	SListInsertAfter(&sl,pos, 6);
	SListEraseAfter(pos);

	SListRemove(&sl, 3);
	SListPrint(&sl);

}


int main()
{

	TestSList();
	system("pause");
	return 0;
}