#pragma once

#include "MyBTreeTemplate.h"
#include "MyStackTemplate.h"
#include <stack>
#include <string>

class ExpressionTree
{
public:
	ExpressionTree();
	virtual ~ExpressionTree();

	MyBinaryTreeTemplate<int *> MakeExpTree(char exp[]);
	//int EvalateExpTree(MyBinaryTreeTemplate<int> *bt);
	int EvalateTree(TreeNode<int> *tn);
private:
};

