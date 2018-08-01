#pragma once
#include <stdio.h>

typedef size_t DType;

struct TreeNode
{
	DType		data;
	TreeNode	*left;
	TreeNode	*right;

	TreeNode(DType data = 0) : data(data), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
	BinaryTree(DType data = 0);
	virtual ~BinaryTree();

	// Making left node.
	TreeNode* MakeLeftSubTree(TreeNode *bt, int data = 0);
	// Making right node.
	TreeNode* MakeRightSubTree(TreeNode *bt, int data = 0);

	void PreorderTree();
	void InorderTree();
	void PostorderTree();

	void DepthOrderTree();
	

	void DeleteNode(TreeNode *bt);

	inline TreeNode *GetRootNode() { return rootNode; }

	int GetData(TreeNode *bt);

	void SetData(TreeNode *bt, int data);

	TreeNode GetNode(TreeNode *bt);
	TreeNode GetLeftSubTree(TreeNode *bt);
	TreeNode GetRightSubTree(TreeNode *bt);


	//inline void SetData()
	static const int ERROR = -1;
private:
	TreeNode	*rootNode;

	// Root node is first.
	void PreorderTraverse(TreeNode *bt);
	// Root node is middle.
	void InorderTraverse(TreeNode *bt);
	// Root node is last.
	void PostporderTraverse(TreeNode *bt);
};

