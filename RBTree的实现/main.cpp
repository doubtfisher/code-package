#include "RBTree.h"

void TestRBTree()
{
	RBTree <int,int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < 9;i++)
	{
		t.Insert(std::make_pair(a[i], a[i]));
	}
	t.Inorder();
}

int main()
{
	TestRBTree();
	system("pause");
	return 0;
}