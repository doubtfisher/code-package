#include "MaxStack.h"

void maxStackTest()
{
	MaxStack* pms = maxStackCreate(10);

	maxStackPush(pms, 1);
	maxStackPush(pms, 5);
	maxStackPush(pms, 15);
	maxStackPush(pms, 15);
	maxStackPush(pms, 7);
	maxStackPush(pms, 8);


	if (!maxStackEmpty(pms))
	{
		printf("top:%d\n", maxStackGetMax(pms));
	}
}

int main()
{
	maxStackTest();
	system("pause");
	return 0;
}