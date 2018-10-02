#pragma once
#include <iostream>

// 부모의 노드를 저장해도 괜찮은지

struct TreeNode
{
	size_t		data;
	TreeNode	*left;
	TreeNode	*right;

	TreeNode(size_t data = 0) : data(data), left(NULL), right(NULL) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree(size_t data);
	~BinarySearchTree();

public:
	void Insert(size_t data);
	
	TreeNode* Search(size_t target);
	size_t Remove(size_t target);
	inline TreeNode* GetLeftSubTree(TreeNode *tNode) { return tNode->left; }
	inline TreeNode* GetRightSubTree(TreeNode *tNode) { return tNode->right; }

	void DepthOrderTree();

	void PreorderTree();
	void InorderTree();
	void PostorderTree();

private:

	// Root node is first.
	void PreorderTraverse(TreeNode *bt);
	// Root node is middle.
	void InorderTraverse(TreeNode *bt);
	// Root node is last.
	void PostporderTraverse(TreeNode *bt);

private:
	TreeNode * rootNode;
};

