
#include "Stack.h"


void StackTest()
{
	Stack s;
	StackInit(&s, 3);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	while (StackEmpty(&s))
	{
		printf("top:%d\n", StackTop(&s));
		StackPop(&s);
	}

}
int main()
{
	StackTest();
	system("pause");
	return 0;
}