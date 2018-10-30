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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 遍历 递归
void BinaryTreePrevOrder(BTNode* root);//前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历
void BinaryTreePostOrder(BTNode* root);//后序遍历
void BinaryTreeLevelOrder(BTNode* root);//层序遍历

// 遍历 非递归
void BinaryTreePrevOrderNonR(BTNode* root);//前序遍历的非递归
void BinaryTreeInOrderNonR(BTNode* root);//中序遍历的非递归
void BinaryTreePostOrderNonR(BTNode* root);//后序遍历的非递归
void TestBinaryTree();


