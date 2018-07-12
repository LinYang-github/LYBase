#include "StdAfx.h"

#include <queue>
#include <assert.h>

#include "BinaryTreeQuestions.h"


BinaryTreeQuestions::BinaryTreeQuestions(void)
{
}


BinaryTreeQuestions::~BinaryTreeQuestions(void)
{
}

int BinaryTreeQuestions::MaxDistance( BinTree BT )
{
	if (BT == NULL)
	{
		return 0;
	}
	int max = 0;
	MaxDistance_p(BT, max);
	return max;
}

int BinaryTreeQuestions::MaxDistance_p( BinTree Curr, int& MaxDis )
{
	if (Curr == NULL)
	{
		return 0;
	}
	int leftDepth = MaxDistance_p(Curr->Left, MaxDis);
	int rightDepth = MaxDistance_p(Curr->Right, MaxDis);
	MaxDis = leftDepth + rightDepth;
	return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
}

bool BinaryTreeQuestions::IsFullBinaryTree( BinTree BT )
{
	if (BT == NULL)
	{
		return true;
	}
	std::queue<BinTree> que;
	que.push(BT);
	BinTree front = NULL;
	while (front = que.front())
	{
		que.push(front->Left);
		que.push(front->Right);
		que.pop();
	}
	while (!que.empty())
	{
		if (que.front() != NULL)
		{
			return false;
		}
		que.pop();
	}
	return true;
}

BinTree BinaryTreeQuestions::FindParent_SearchTree( BinTree Node1, BinTree Node2, BinTree Root )
{
	if (Root == NULL)
	{
		return NULL;
	}
	if (Node1 == NULL)
	{
		return Node2;
	}
	if (Node2 == NULL)
	{
		return Node1;
	}
	while (1)
	{
		if (Root == NULL)
		{
			assert(false);
		}
		if ((Root->Data >= Node1->Data && Root->Data <= Node2->Data)
			|| (Root->Data >= Node2->Data && Root->Data <= Node1->Data))
		{
			return Root;
		}
		else if (Root->Data > Node1->Data)
		{
			Root = Root->Left;
		}
		else
		{
			Root = Root->Right;
		}
	}
}

BinTree BinaryTreeQuestions::NearestParent( BinTree Node1, BinTree Node2, BinTree Root )
{
	if (Root == NULL)
	{
		return NULL;
	}
	if (Node1 == NULL || Node2 == NULL)
	{
		assert(false);
	}
	
	std::pair<BinTree, int> ret = NearestParent_p(Root, Node1, Node2);
	return ret.first;
}

std::pair<BinTree, int> BinaryTreeQuestions::NearestParent_p( BinTree Root, BinTree Node1, BinTree Node2 )
{
	if (Root == NULL)
	{
		return std::pair<BinTree, int>();
	}
	std::pair<BinTree, int> left_pair = NearestParent_p(Root->Left, Node1, Node2);
	std::pair<BinTree, int> right_pair = NearestParent_p(Root->Right, Node1, Node2);
	if (left_pair.second == 2)
	{
		return left_pair;
	}
	if (right_pair.second == 2)
	{
		return right_pair;
	}
	int x = 0;
	if (Root == Node1 || Root == Node2)
	{
		x = 1;
	}
	return std::pair<BinTree, int>(Root, left_pair.second + right_pair.second + x);
}

BinTree BinaryTreeQuestions::BinaryTreeToList( BinTree Root )
{
	if (Root == NULL)
	{
		return NULL;
	}
	BinTree head = Root;
	while (head->Left != NULL)
	{
		head = head->Left;
	}
	BinTree prev = NULL;
	BinaryTreeToList_p(Root, prev);
	return head;
}

void BinaryTreeQuestions::BinaryTreeToList_p( BinTree Root, BinTree & Prev )
{
	if (Root == NULL)
	{
		return;
	}
	BinaryTreeToList_p(Root->Left, Prev);
	Root->Left = Prev;
	if (Prev)
	{
		Prev->Right = Root;
	}
	Prev = Root;
	BinaryTreeToList_p(Root->Right, Prev);
}
