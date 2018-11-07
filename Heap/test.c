# include "Heap.h"

HeapTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapInit(&hp);
	HeapCreate(&hp, a, sizeof(a) / sizeof(HPDataType));
	HeapPrint(&hp);

	HeapPush(&hp, 70);
	HeapPush(&hp, 45);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapSort(&hp);
	HeapPrint(&hp);
}

int main()
{
	HeapTest();
	system("pause");
	return 0;
}