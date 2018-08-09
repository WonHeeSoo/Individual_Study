#pragma once

#include "MyBTreeTemplate.h"
#include "MyStackTemplate.h"
#include <stack>
#include <string>

class ExpressionTree
{
public:
	ExpressionTree();
	~ExpressionTree();

	int MakeExpTree(char exp[]);
	int EvalateExpTree(BinaryTree<int> *bt);
	int EvalateTree(TreeNode<int> *tn);
private:
};

