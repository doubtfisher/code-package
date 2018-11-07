#include "Heap.h"

void Swap(HPDataType* pd1, HPDataType* pd2)
{
	HPDataType d = *pd1;
	*pd1 = *pd2;
	*pd2 = d;
}
void HeapInit(Heap* pHeap)
{
	assert(pHeap);
	pHeap->_array = NULL;
	pHeap->_size = 0;
	pHeap->_capacity = 0;
}

void AdjustDown(int* a, int n, int root)//大堆的向下调整
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n-1)
	{
		//选左右孩子中较大的
		if (child + 1 < n &&a[child + 1] > a[child])//默认child为最大的，如果child+1为最大，child就要加1才能变为最大
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//void AdjustDown(int* a, int n, int root)//小堆的向下调整
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//选左右孩子中较小的
//		if (child + 1 < n &&a[child + 1] < a[child])//默认child为最大的，如果child+1为最大，child就要加1才能变为最大
//		{
//			child++;
//		}
//		if (a[parent] >a[child])
//		{ 
//			Swap(&a[parent], &a[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

void AdjustUp(int* a, int n, int child)//向上调整
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapCreate(Heap* pHeap, HPDataType* a, int n)
{
	assert(pHeap);
	pHeap->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(pHeap->_array, a, sizeof(HPDataType)*n);
	pHeap->_size = pHeap->_capacity = n;
	
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(pHeap->_array, pHeap->_size, i);
	}

}

void HeapDestroy(Heap* pHeap)
{
	assert(pHeap);
	free(pHeap->_array);
	pHeap->_array = NULL;
	pHeap->_size = 0;
	pHeap->_capacity = 0;
}

void HeapPush(Heap* pHeap, HPDataType x)
{
	assert(pHeap);
	size_t newcapacity = pHeap->_capacity == 0 ? 3 : pHeap->_capacity * 2;
	if (pHeap->_size == pHeap->_capacity)
	{
		pHeap->_capacity =(HPDataType)realloc(pHeap->_array, sizeof(HPDataType)*newcapacity);
		pHeap->_capacity = newcapacity;
	}
	pHeap->_array[pHeap->_size++] = x;
	AdjustUp(pHeap->_array, pHeap->_size, pHeap->_size - 1);
}

void HeapPop(Heap* pHeap)
{
	assert(pHeap);
	Swap(&pHeap->_array[0], &pHeap->_array[pHeap->_size - 1]);//一定要记得取地址！！！
	pHeap->_size--;
	AdjustDown(pHeap->_array, pHeap->_size, 0);
	
}

HPDataType HeapTop(Heap* pHeap)
{
	assert(pHeap);
	return pHeap->_array[0];
}

int HeapSize(Heap* pHeap)
{
	assert(pHeap);
	return pHeap->_size;
}

int HeapEmpty(Heap* pHeap)
{
	assert(pHeap);
	return pHeap->_size == 0 ? 0 : 1;
}

void HeapSort(Heap* pHeap)
{
	assert(pHeap);
	for (int i = (pHeap->_size - 2) / 2; i >0; i--)//建堆
	{
		AdjustDown(pHeap->_array, pHeap->_size, i);
	}
	//排序
	int end = pHeap->_size-1;
	while (end > 0)
	{
		Swap(&pHeap->_array[0], &pHeap->_array[end]);
		AdjustDown(pHeap->_array, end, 0);
		end--;
	}
}
void HeapPrint(Heap* pHeap)
{
	assert(pHeap);
	for (int i = 0; i < pHeap->_size; i++)
	{
		printf("%d ", pHeap->_array[i]);
	}
	printf("\n");
}
void PrintArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}