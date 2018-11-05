#include "QuickSortR.h"

void SortTest()
{
	int a[10] = { 5, 2, 4, 6, 1, 3, 8, 7, 9, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	printf("¿ìËÙÅÅÐò:>");
	QuickSortR(a,0,sz-1);
	PrintArray(a, sz);
}



int main()
{
	SortTest();
	system("pause");
	return 0;
}