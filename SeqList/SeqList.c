#include "SeqList.h"


void SeqListInit(SeqList* psl, size_t capacity)//初始化
{
	assert(psl);
	if (capacity == 0)
	{
		psl->_a = NULL;
		psl->_size = 0;
		psl->_capacity = 0;
	}
	else
	{
		psl->_a = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
		psl->_size =0;
		psl->_capacity = capacity;
		assert(psl->_a);
	}
}

void SeqListDestory(SeqList* psl)//销毁
{
	assert(psl);
	free(psl->_a);
	psl->_a = NULL;
	psl->_size = 0;
	psl->_capacity = 0;
}
void CheckCapacity(SeqList* psl)//容量检测
{
	if (psl->_size == psl->_capacity)
	{
		SLDataType* tmp;
		if (psl->_capacity == 0)
		{
			psl->_capacity = 2;
		}
		else
		{
			tmp = realloc(psl->_a, psl->_capacity * 2 * sizeof(SLDataType));
			assert(tmp);
			psl->_a = tmp;
			psl->_capacity *= 2;
		}
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)//尾上插入数据
{
	assert(psl);
	int end;
	CheckCapacity(psl);
	end = psl->_size;
	while (end >= 1)
	{
		psl->_a[end] = psl->_a[end - 1];
		end--;
	}
	psl->_a[0] = x;
	psl->_size++;
}

void SeqListPopBack(SeqList* psl)//尾上删除数据
{
	assert(psl);
	if (psl->_size > 0)
	{
		psl->_size--;
	}

}

void PushFront(SeqList* psl, SLDataType x)//头部插入数据
{
	assert(psl);
	int end;
	CheckCapacity(psl);
	end = psl->_size;
	while (end >=0)//??
	{
		psl->_a[end + 1] = psl->_a[end];
		end--;
	}
	psl->_a[0] = x;
	psl->_size++;
}

void PopFront(SeqList* psl)//删除头部数据
{
	assert(psl);
	if (psl->_size > 0)
	{
		int start;
		start = psl->_a[0];
		while (start < psl->_a[psl->_size-1])
		{
			psl->_a[start] = psl->_a[start + 1];
			start++;
		}
		psl->_size--;
	}
}

int SeqListFind(SeqList* psl, SLDataType x)//O(N)
{
	assert(psl);
	size_t i = 0;
	for (i = 0; i < psl->_size; i++)
	{
		if (psl->_a[i]==x)
		{
			/*printf("%3d\n",i);*/
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//任何位置的插入数据
{
	int end;
	assert(psl&&pos<=psl->_size);
	CheckCapacity(psl);
	end = psl->_size - 1;
	while ((int)pos <= end)
	{
		psl->_a[end + 1] = psl->_a[end];
		end--;
	}
	psl->_a[pos] = x;
	psl->_size++;
}

void SeqListErase(SeqList* psl, size_t pos)//删除某个位置的数据
{
	assert(psl&&pos<psl->_size);
	size_t start=pos;
	while (start<psl->_size-1)
	{
		psl->_a[start] = psl->_a[start + 1];
		start++;
	}
	psl->_size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)//删除某个数值
{
	assert(psl);
	size_t  pos;
	pos = SeqListFind(psl, x);
	if (pos != -1)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//修改某个位置的数据
{
	assert(psl&&pos<psl->_size);
	psl->_a[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	size_t i = 0;
	assert(psl);
	for (i = 0; i < psl->_size; i++)
	{
		printf("%3d", psl->_a[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* psl)//冒泡排序
{
	assert(psl);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < psl->_size - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < psl->_size - 1 - i; j++)
		{
			if (psl->_a[j]>psl->_a[j + 1])
			{
				SLDataType tmp = psl->_a[j+1];
				psl->_a[j + 1] = psl->_a[j];
				psl->_a[j] = tmp;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			return;
		}
	}
}

int BinarySearch(SeqList* psl,SLDataType x)//二分查找
{
	assert(psl);
	int left = 0;
	int right = psl->_size - 1;
	while (left <= right)
	{
		SLDataType mid = left + (right - left);
		if (psl->_a[mid] < x)
		{
			left = mid+1;
		}
		else if (psl->_a[mid] > x)
		{
			right = mid-1;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}

void SeqListRemoveAll(SeqList* psl, SLDataType x)//要求时间复杂度是O(N) 空间复杂度O(1)
{
	assert(psl);
	SLDataType ret = 0;
	size_t i = 0;
	while (i < psl->_size - 1)
	{
		ret = SeqListFind(psl, x);
		if (ret != -1)
		{
			SeqListRemove(psl, x);
		}
		i++;
	}
}

void SelectSort(SeqList* psl)
{
	assert(psl);
		size_t min = 0;
		size_t max = 0;	
		size_t left = 0;	
		size_t right = psl->_size - 1;
		while (left<right)	
		{
		   for (size_t i = left; i <= right; i++)	
		   {
			   if (psl->_a[min]>psl->_a[i])		
			   { 
				min = i;
			   }			
			  if (psl->_a[max] < psl->_a[i])	
			   {
				max = i;
			   }
		}		
		SLDataType x = psl->_a[min];
		psl->_a[min] = psl->_a[left];	
		psl->_a[left] = x;		
		if (max == left)
		{
			max = min;
		}
		x = psl->_a[max];	
		psl->_a[max] = psl->_a[right];	
		psl->_a[right] = x;
		}
}

