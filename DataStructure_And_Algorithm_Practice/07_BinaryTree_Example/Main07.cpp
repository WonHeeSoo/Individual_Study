#include "BinaryTree.h"

int main()
{
	BinaryTree *BT = new BinaryTree(1);

	TreeNode	*a, *b, *c;

	a = BT->MakeLeftSubTree(BT->GetRootNode(), 2);
	b = BT->MakeRightSubTree(BT->GetRootNode(), 3);

	BT->MakeLeftSubTree(a, 4);
	BT->MakeRightSubTree(a, 5);
	c = BT->MakeLeftSubTree(b, 6);
	BT->MakeRightSubTree(b, 7);

	BT->MakeLeftSubTree(c, 8);
	BT->MakeRightSubTree(c, 9);

	BT->PreorderTree();
	BT->InorderTree();
	BT->PostorderTree();
	BT->DepthOrderTree();
	return 0;
}