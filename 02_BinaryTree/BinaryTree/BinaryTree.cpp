// BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

#include "BinaryTreeTraversal.h"
#include "BinaryTreeQuestions.h"

BinTree CreateBinaryTree()
{
	//1 2 4 0 0 5 0 0 3 6 0 0 7 0 0 
	BinTree BT;
	int data;
	std::cin >> data;
	if (data == 0)
	{
		BT = NULL;
	}
	else
	{
		BT = (BinTree)malloc(sizeof(TreeNode));
		BT->Data = data;
		BT->Left = CreateBinaryTree();
		BT->Right = CreateBinaryTree();
	}
	return BT;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BinTree BT = CreateBinaryTree();
	if (BT)
	{
		//二叉树遍历测试
		printf("Test-PreOrderTraversal_Re:");
		BinaryTreeTraversal::PreOrderTraversal_Re(BT);
		printf("\n");

		printf("Test-PreOrderTraversal_Stack:");
		BinaryTreeTraversal::PreOrderTraversal_Stack(BT);
		printf("\n");

		printf("Test-InOrderTraversal_Re:");
		BinaryTreeTraversal::InOrderTraversal_Re(BT);
		printf("\n");

		printf("Test-InOrderTraversal_Stack:");
		BinaryTreeTraversal::InOrderTraversal_Stack(BT);
		printf("\n");

		printf("Test-InOrderTraversal:");
		BinaryTreeTraversal::InOrderTraversal(BT);
		printf("\n");

		printf("Test-PostOrderTraversal_Re:");
		BinaryTreeTraversal::PostOrderTraversal_Re(BT);
		printf("\n");

		printf("Test-PostOrderTraversal_Stack:");
		BinaryTreeTraversal::PostOrderTraversal_Stack(BT);
		printf("\n");

		printf("Test-PostOrderTraversal_Stack_2:");
		BinaryTreeTraversal::PostOrderTraversal_Stack_2(BT);
		printf("\n");

		printf("Test-LevelOrderTraversal:");
		BinaryTreeTraversal::LevelOrderTraversal(BT);
		printf("\n");

		//二叉树各问题测试
		printf("Test-MaxDistance:");
		int max = BinaryTreeQuestions::MaxDistance(BT);
		printf("%d\n", max);

		printf("Test-IsFullBinaryTree:");
		bool isFull = BinaryTreeQuestions::IsFullBinaryTree(BT);
		printf("%d\n", isFull);

		printf("Test-BinaryTreeToList:");
		BinTree btList = BinaryTreeQuestions::BinaryTreeToList(BT);
		//BinaryTreeTraversal::LevelOrderTraversal(btList);
		printf("\n");

	}

	system("pause");
	return 0;
}

