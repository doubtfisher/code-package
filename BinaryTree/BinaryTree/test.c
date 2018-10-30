# include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"

void BinaryTreeTest()
{
	char* array = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* tree = BinaryTreeCreate(array, &i);
	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	BinaryTreePrevOrder(tree); //递归的前序遍历
	printf("\n");
	printf("\n");
	BinaryTreeInOrder(tree);//递归的中序序遍历
	printf("\n");
	printf("\n");
	BinaryTreePostOrder(tree);//递归的后序遍历
	printf("\n");
	printf("\n");
    BinaryTreeLevelOrder(tree);//层序遍历
	printf("\n");
	printf("\n");
	BinaryTreePrevOrderNonR(tree);//非递归的前序遍历
	printf("\n");
	BinaryTreeInOrderNonR(tree);//中序遍历的非递归
	printf("\n");
	BinaryTreePostOrderNonR(tree);//后序遍历的非递归
}

int main()
{
	BinaryTreeTest();
	system("pause");
	return 0;

}