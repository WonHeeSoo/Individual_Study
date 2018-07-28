#pragma once
#include <stdio.h>

struct TreeNode
{
	size_t		data;
	TreeNode	*left;
	TreeNode	*right;

	TreeNode() : left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
	BinaryTree();
	virtual ~BinaryTree();

	// Making left node.
	void MakeLeftSubTree(TreeNode *bt);
	// Making right node.
	void MakeRightSubTree(TreeNode *bt);

	// Root node is first.
	void PreorderTraverse(TreeNode *bt);
	// Root node is middle.
	void InorderTraverse(TreeNode *bt);
	// Root node is last.
	void PostporderTraverse(TreeNode *bt);

	void DeleteNode(TreeNode *bt);

	inline TreeNode GetRootNode() { return *rootNode; }

	int GetData(TreeNode *bt);

	TreeNode GetNode(TreeNode *bt);
	TreeNode GetLeftSubTree(TreeNode *bt);
	TreeNode GetRightSubTree(TreeNode *bt);


	//inline void SetData()
	static const int ERROR = -1;
private:
	TreeNode	*rootNode;

};

