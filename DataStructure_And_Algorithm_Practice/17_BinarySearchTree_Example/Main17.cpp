#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree *BST = new BinarySearchTree(3);

	BST->Insert(1);
	BST->Insert(7);
	BST->Insert(4);
	BST->Insert(2);

	BST->PostorderTree();

	BST->Insert(1);

	BST->PostorderTree();

	BST->Insert(9);
	BST->Insert(5);

	BST->PostorderTree();

	BST->Remove(7);

	BST->PostorderTree();

	BST->Remove(1);

	BST->PostorderTree();

	return 0;
}