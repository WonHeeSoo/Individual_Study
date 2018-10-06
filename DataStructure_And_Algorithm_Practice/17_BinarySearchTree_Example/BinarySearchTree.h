#pragma once
#include <iostream>

typedef unsigned	data_t;

struct TreeNode
{
	data_t		data;
	TreeNode	*left;
	TreeNode	*right;

	TreeNode(data_t data = 0) : data(data), left(NULL), right(NULL) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

public:
	void Insert(data_t data);
	
	TreeNode* Search(data_t target) const;
	bool Remove(data_t target);
	inline TreeNode* GetLeftSubTree(TreeNode *tNode) { return tNode->left; }
	inline TreeNode* GetRightSubTree(TreeNode *tNode) { return tNode->right; }

	void DepthOrderTree() const;

	void PreorderTree() const;
	void InorderTree() const;
	void PostorderTree() const;

private:

	// Root node is first.
	void PreorderTraverse(TreeNode *bt) const;
	// Root node is middle.
	void InorderTraverse(TreeNode *bt) const;
	// Root node is last.
	void PostporderTraverse(TreeNode *bt) const;

	void RemoveTree();

	void UpdateParent(TreeNode *parent, TreeNode *toBeDeleted, TreeNode *newChild);

private:
	TreeNode	*rootNode;
};

