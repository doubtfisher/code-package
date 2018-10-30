#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "Queue.h"
#include "Stack.h"


typedef char BTDataType ;
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	BTDataType _data;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ���� �ݹ�
void BinaryTreePrevOrder(BTNode* root);//ǰ�����
void BinaryTreeInOrder(BTNode* root);//�������
void BinaryTreePostOrder(BTNode* root);//�������
void BinaryTreeLevelOrder(BTNode* root);//�������

// ���� �ǵݹ�
void BinaryTreePrevOrderNonR(BTNode* root);//ǰ������ķǵݹ�
void BinaryTreeInOrderNonR(BTNode* root);//��������ķǵݹ�
void BinaryTreePostOrderNonR(BTNode* root);//��������ķǵݹ�
void TestBinaryTree();


