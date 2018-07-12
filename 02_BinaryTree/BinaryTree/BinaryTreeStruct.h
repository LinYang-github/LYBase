#ifndef Struct_h__
#define Struct_h__

typedef struct TreeNode *PtrToNode;
typedef struct TreeNode *BinTree;

struct TreeNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};


#endif // Struct_h__
