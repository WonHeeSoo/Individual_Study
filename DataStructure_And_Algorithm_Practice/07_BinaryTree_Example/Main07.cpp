#include "BinaryTree.h"

int main()
{
	BinaryTree *BT = new BinaryTree();
	BT->PreorderTraverse(BT->GetRootNode);
}