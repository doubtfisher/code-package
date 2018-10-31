#include "MaxStack.h"

MaxStack* maxStackCreate(int maxSize)
{
	MaxStack* pst = (MaxStack*)malloc(sizeof(MaxStack));
	pst->pst = (int*)malloc(sizeof(int)*maxSize);
	pst->stTop = 0;
	pst->pmaxST = (int*)malloc(sizeof(int)*maxSize);
	pst->maxSTTop = 0;

	return pst;
}

void maxStackPush(MaxStack* obj, int x)
{
	int* pst = obj->pst;//正常栈
	int* pmaxST = obj->pmaxST;//最大栈
	pst[obj->stTop++]=x;
	if (obj->maxSTTop == 0 || x >= pmaxST[obj->maxSTTop - 1])
	{
		pmaxST[obj->maxSTTop++]=x;
	}
}

void maxStackPop(MaxStack* obj)
{
	int* pst = obj->pst;
	int* pmaxST = obj->pmaxST;
	if (pst[obj->stTop - 1] == pmaxST[obj->maxSTTop - 1])
	{
		obj->maxSTTop--;
	}
	obj->stTop--;
}

int maxStackTop(MaxStack* obj)
{

	return obj->pst[--obj->stTop];
	
}

int maxStackGetMax(MaxStack* obj)
{
	return obj->pmaxST[obj->maxSTTop - 1 ];
	
}

int maxStackEmpty(MaxStack* obj)
{
	if(obj->stTop == 0 )
	{
		return 1;
	}
	return 0;
}

 void  maxStackFree(MaxStack* obj)
{
	free(obj->pst);
	free(obj->pmaxST);
	free(obj);
}
