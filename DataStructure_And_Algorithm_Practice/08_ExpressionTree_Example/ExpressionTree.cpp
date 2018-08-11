#include "ExpressionTree.h"



ExpressionTree::ExpressionTree()
{
}


ExpressionTree::~ExpressionTree()
{
}

MyBinaryTreeTemplate<int *> ExpressionTree::MakeExpTree(char exp[])
{
	MyStackTemplate<int> *stack = new MyStackTemplate<int>();
	MyBinaryTreeTemplate<int> *bTree = new MyBinaryTreeTemplate<int>();
	int expLen = strlen(exp);

	for (int i = 0; i < expLen; i++)
	{
		TreeNode<int> *tnode = new TreeNode<int>();
		if (isdigit(exp[i]))
		{
			tnode->data = (exp[i] - '0');
		}
		else
		{
			tnode->right->data = stack->Pop();
			tnode->left->data = stack->Pop();
			tnode->data = exp[i];
		}
		stack->Push(tnode);
	}
	return bTree->SetNode(stack->Pop());
}

/*int ExpressionTree::EvalateExpTree(MyBinaryTreeTemplate<int> *bt)
{
	
	if (bt->GetRootNode()->left == NULL && bt->GetRootNode()->right == NULL)
		return bt->GetData(bt->GetRootNode());

	int op1, op2;
	op1 = EvalateTree(bt->GetRootNode()->left);
	op2 = EvalateTree(bt->GetRootNode()->right);

	switch (bt->GetData(bt->GetRootNode()))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}*/

int ExpressionTree::EvalateTree(TreeNode<int> * tn)
{
	if (tn->left == NULL && tn->right == NULL)
		return tn->data;

	int op1, op2;
	op1 = EvalateTree(tn->left);
	op2 = EvalateTree(tn->right);

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
	}
	return 0;
}
