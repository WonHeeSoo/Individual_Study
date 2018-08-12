#include "ExpressionTree.h"
#include <assert.h>
#include <iostream>

using namespace std;
using namespace ExpressionTree;

namespace ExpressionTree {

	MyBinaryTreeTemplate<char>* MakeExpTree(char exp[])
	{
		MyStackTemplate<TreeNode<char>*> stack;

		size_t expLen = strlen(exp);

		for (int i = 0; i < expLen; i++)
		{
			TreeNode<char> *tnode = new TreeNode<char>();
			if (!isdigit(exp[i]))
			{
				tnode->right = stack.Pop();
				tnode->left = stack.Pop();
			}
			tnode->data = exp[i];
			stack.Push(tnode);
		}
		MyBinaryTreeTemplate<char> *bTree = new MyBinaryTreeTemplate<char>();
		bTree->SetRootNode(stack.Pop());
		assert(stack.IsEmpty());
		return bTree;
	}

	int EvaluateNode(TreeNode<char> * tn)
	{
		if (tn->left == NULL && tn->right == NULL)
		{
			// 'tn' contains a value.
			assert(isdigit(tn->data));
			return tn->data - '0';
		}


		// 'tn' contains a binary operator.
		int op1, op2;
		op1 = EvaluateNode(tn->left);
		op2 = EvaluateNode(tn->right);

		switch (tn->data)
		{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		default:
			cerr << "# ERROR : This case is error." << endl;
			assert(false);
			return 0;
		}
	}
}