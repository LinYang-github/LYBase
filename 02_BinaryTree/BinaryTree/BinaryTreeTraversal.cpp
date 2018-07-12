#include "StdAfx.h"

#include <stack>
#include <queue>

#include "BinaryTreeTraversal.h"


BinaryTreeTraversal::BinaryTreeTraversal(void)
{
}


BinaryTreeTraversal::~BinaryTreeTraversal(void)
{
}

void BinaryTreeTraversal::PreOrderTraversal_Re( BinTree BT )
{
	if (BT)
	{
		printf("%d ",BT->Data);
		PreOrderTraversal_Re(BT->Left);
		PreOrderTraversal_Re(BT->Right);
	}
}

void BinaryTreeTraversal::PreOrderTraversal_Stack( BinTree BT )
{
	BinTree T = BT;
	std::stack<BinTree> S;
	while (T || !S.empty())
	{
		while (T)
		{
			printf("%d ",T->Data);
			S.push(T);
			T = T->Left;
		}

		if (!S.empty())
		{
			T = S.top();
			S.pop();
			T = T->Right;
		}
	}
}

void BinaryTreeTraversal::InOrderTraversal_Re( BinTree BT )
{
	if (BT)
	{
		InOrderTraversal_Re(BT->Left);
		printf("%d ",BT->Data);
		InOrderTraversal_Re(BT->Right);
	}
}

void BinaryTreeTraversal::InOrderTraversal_Stack( BinTree BT )
{
	BinTree T = BT;
	std::stack<BinTree> S;
	while (T || !S.empty())
	{
		while (T)
		{
			S.push(T);
			T = T->Left;
		}

		if (!S.empty())
		{
			T = S.top();
			S.pop();
			printf("%d ",T->Data);
			T = T->Right;
		}
	}
}

void BinaryTreeTraversal::InOrderTraversal( BinTree BT )
{
	BinTree B = BT;
	while (B)
	{
		BinTree pLeft = B->Left;
		if (pLeft)
		{
			//�ҵ���BΪ���ڵ���������Һ���
			while (pLeft->Right && pLeft->Right != B)
			{
				pLeft = pLeft->Right;
			}

			if (pLeft->Right == NULL)
			{
				pLeft->Right = B;
				B = B->Left;
				continue;
			}
			else
			{
				pLeft->Right = NULL;
			}
		}

		printf("%d ",B->Data);
		B = B->Right;
	}
}

void BinaryTreeTraversal::PostOrderTraversal_Re( BinTree BT )
{
	if (BT)
	{
		PostOrderTraversal_Re(BT->Left);
		PostOrderTraversal_Re(BT->Right);
		printf("%d ",BT->Data);
	}
}

void BinaryTreeTraversal::PostOrderTraversal_Stack( BinTree BT )
{
	BinTree T = BT;
	std::stack<BinTree> S1;
	std::stack<BinTree> S2;
	while (T || !S1.empty())
	{
		//һֱ���Ҳ�����;�ڵ���ʣ�ѹ��S2����ѹ���ջS1
		while (T)
		{
			S2.push(T);
			S1.push(T);
			T = T->Right;
		}

		if (!S1.empty())
		{
			T = S1.top();
			S1.pop();
			T = T->Left;
		}
	}
	while (!S2.empty())
	{
		T = S2.top();
		S2.pop();
		printf("%d ",T->Data);
	}
}

void BinaryTreeTraversal::PostOrderTraversal_Stack_2( BinTree BT )
{
	if (BT == NULL)
	{
		return;
	}
	std::stack<BinTree> S;
	BinTree Prev = NULL, Curr = NULL;
	S.push(BT);
	while (!S.empty())
	{
		Curr = S.top();
		//��PrevΪNULL����Curr�ĸ��ڵ�
		if (Prev == NULL || Prev->Left == Curr || Prev->Right == Curr)
		{
			if (Curr->Left != NULL)
			{
				S.push(Curr->Left);
			} 
			else if (Curr->Right != NULL)
			{
				S.push(Curr->Right);
			}
		}
		else if (Curr->Left == Prev)//��Prev��Curr�������
		{
			if (Curr->Right != NULL)
			{
				S.push(Curr->Right);
			}
		}
		else
		{
			printf("%d ",Curr->Data);
			S.pop();
		}
		Prev = Curr;//�����굱ǰ�ڵ��Curr�ڵ��ΪPrev�ڵ�
	}
}

void BinaryTreeTraversal::LevelOrderTraversal( BinTree BT )
{
	BinTree T;
	std::queue<BinTree> Q;
	if (BT == NULL)
	{
		return;
	}
	Q.push(BT);
	while (!Q.empty())
	{
		T = Q.front();
		Q.pop();
		printf("%d ",T->Data);
		if (T->Left)
		{
			Q.push(T->Left);
		}
		if (T->Right)
		{
			Q.push(T->Right);
		}
	}
}
