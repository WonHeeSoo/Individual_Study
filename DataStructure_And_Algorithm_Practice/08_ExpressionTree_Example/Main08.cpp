#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*";
	MyBinaryTreeTemplate<char> *expTree;
	expTree = ExpressionTree::MakeExpTree(exp);

	int result = ExpressionTree::EvaluateTree(expTree);

	printf("Result : %d", result);
	return 0;
}