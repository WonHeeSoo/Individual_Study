#pragma once

#include "MyBTreeTemplate.h"
#include "MyStackTemplate.h"
#include <stack>
#include <string>

namespace ExpressionTree
{
	MyBinaryTreeTemplate<char>* MakeExpTree(char exp[]);

	int EvaluateNode(TreeNode<char> *tn);

	inline int EvaluateTree(MyBinaryTreeTemplate<char> *bt) { return EvaluateNode(bt->GetRootNode()); }

};
