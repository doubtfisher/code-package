#include "SeqList.h"


int main()
{
	TestSeqList();
	system("pause");
	return 0;
}

void TestSeqList()
{
	SeqList sl;
	SeqListInit(&sl, 10);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	PushFront(&sl, 0);
	SeqListPrint(&sl);

	PopFront(&sl);
	SeqListPrint(&sl);

	SeqListFind(&sl, 4);
	SeqListInsert(&sl, 2, 6);
	SeqListPrint(&sl);

	SeqListErase(&sl, 3);
	SeqListPrint(&sl);

	SeqListModify(&sl, 1, 7);
	SeqListPrint(&sl);

	SeqListRemove(&sl, 7);
	SeqListPrint(&sl);

	SeqListBubbleSort(&sl);
	SeqListPrint(&sl);

	printf("%d\n",BinarySearch(&sl,2));
	

	SeqListRemoveAll(&sl, 6);
	SeqListPrint(&sl);
	

	/*SelectSort(&sl);
	SeqListPrint(&sl);*/
}