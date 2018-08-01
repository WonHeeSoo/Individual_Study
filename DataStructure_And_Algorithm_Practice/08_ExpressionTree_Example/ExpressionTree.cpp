#include "ExpressionTree.h"



ExpressionTree::ExpressionTree()
{
}


ExpressionTree::~ExpressionTree()
{
}

int ExpressionTree::MakeExpTree(char exp[])
{
	ArrayStack *stack = new ArrayStack();
	
	int expLen = strlen(exp);

	for (int i = 0; i < expLen; i++)
	{
		BinaryTree *BT = new BinaryTree();;
		if (isdigit(exp[i]))
		{
			BT->SetData(BT->GetRootNode(), exp[i] - '0');
		}
		else
		{
			BT->MakeRightSubTree(BT->GetRootNode(), stack->Pop());
			BT->MakeLeftSubTree(BT->GetRootNode(), stack->Pop());
			BT->SetData(BT->GetRootNode(), exp[i]);
		}
		stack->Push(BT->GetRootNode()->data);
	}
	return stack->Pop();
}
