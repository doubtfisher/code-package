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
	BinaryTreePrevOrder(tree); //�ݹ��ǰ�����
	printf("\n");
	printf("\n");
	BinaryTreeInOrder(tree);//�ݹ�����������
	printf("\n");
	printf("\n");
	BinaryTreePostOrder(tree);//�ݹ�ĺ������
	printf("\n");
	printf("\n");
    BinaryTreeLevelOrder(tree);//�������
	printf("\n");
	printf("\n");
	BinaryTreePrevOrderNonR(tree);//�ǵݹ��ǰ�����
	printf("\n");
	BinaryTreeInOrderNonR(tree);//��������ķǵݹ�
	printf("\n");
	BinaryTreePostOrderNonR(tree);//��������ķǵݹ�
}

int main()
{
	BinaryTreeTest();
	system("pause");
	return 0;

}