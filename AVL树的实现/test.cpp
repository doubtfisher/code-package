#include "AVLTree.h"

void TestAVLTree()
{
	AVLTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
		cout << t.IsBalance() <<"->"<<e<< endl;
	}
	t.Inorder();

	cout << t.IsBalance() << endl;
}
int main()
{
	TestAVLTree();
	system("pause");
	return 0;
}