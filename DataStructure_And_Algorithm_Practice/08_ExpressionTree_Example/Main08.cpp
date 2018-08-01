#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*";
	ExpressionTree *eTree = new ExpressionTree();
	eTree->MakeExpTree(exp);
	return 0;
}