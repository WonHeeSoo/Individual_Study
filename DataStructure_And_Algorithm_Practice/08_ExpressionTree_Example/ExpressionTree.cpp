#include "ExpressionTree.h"



ExpressionTree::ExpressionTree()
{
}


ExpressionTree::~ExpressionTree()
{
}

int ExpressionTree::MakeExpTree(char exp[])
{
	MyStackTemplate<int> *stack = new MyStackTemplate<int>();
	BinaryTree<int> *bTree = new BinaryTree<int>(0);
	int expLen = strlen(exp);

	for (int i = 0; i < expLen; i++)
	{
		TreeNode<int> *tnode = new TreeNode<int>(0);
		if (isdigit(exp[i]))
		{
			//bTree->SetData(bTree->GetRootNode(), exp[i] - '0');
			tnode->data = (exp[i] - '0');
		}
		else
		{
			//bTree->MakeRightSubTree(bTree->GetRootNode(), stack->Pop());
			//bTree->MakeLeftSubTree(bTree->GetRootNode(), stack->Pop());
			//bTree->SetData(bTree->GetRootNode(), exp[i]);
			tnode->right->data = stack->Pop();
			tnode->left->data = stack->Pop();
			tnode->data = exp[i];
		}
		//stack->Push(bTree->GetRootNode()->data);
		//stack->Push(tnode);
	}
	return stack->Pop();
}

int ExpressionTree::EvalateExpTree(BinaryTree<int> * bt)
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
}

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
