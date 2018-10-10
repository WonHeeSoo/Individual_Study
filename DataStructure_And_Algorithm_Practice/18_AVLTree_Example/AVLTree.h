#include "BinarySearchTree.h"
#include <iostream>

#pragma once

typedef unsigned data_t;
typedef int func(int a);

struct TreeNode
{
	data_t		value;
	TreeNode	*left;
	TreeNode	*right;
	int			heightDiff;
	TreeNode(data_t value) : value(value), left(NULL), right(NULL), heightDiff(0) {}
	func(value);
};

class AVLTree
{
public:
	AVLTree();
	virtual ~AVLTree();

public:
	void Insert(data_t value);
	bool Remove(data_t value);

	int GetHeightDiff(TreeNode *node);


private:
	void RemoveTree();
	
	void Rebalance();
	void RotateLL(TreeNode *node);
	void RotateRR(TreeNode *node);
	void RotateLR(TreeNode *node);
	void RotateRL(TreeNode *node);

private:
	TreeNode	*rootNode;
};

