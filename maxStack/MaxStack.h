#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct MaxStack
{
	int* pst;
	int stTop;
	int* pmaxST;
	int maxSTTop;
}MaxStack;

MaxStack* maxStackCreate(int maxSize);
void maxStackPush(MaxStack* obj, int x);
void maxStackPop(MaxStack* obj);
int maxStackTop(MaxStack* obj);
int maxStackGetMax(MaxStack* obj);
int maxStackEmpty(MaxStack* obj);
void maxStackFree(MaxStack* obj);

