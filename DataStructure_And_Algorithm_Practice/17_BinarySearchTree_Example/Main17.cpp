#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "BinarySearchTree.h"

void generate_randIntArray(int max_val, size_t size, BinarySearchTree *bst)
{
	for (int i = 0; i < size; i++)
		bst->Insert(rand() % max_val);
}

int main()
{
	BinarySearchTree *BST = new BinarySearchTree();

	generate_randIntArray(6, 21, BST);
	/*BST->Insert(1);
	BST->Insert(7);
	BST->Insert(4);
	BST->Insert(2);

	BST->InorderTree();

	BST->Insert(1);

	BST->InorderTree();

	BST->Insert(9);
	BST->Insert(5);

	BST->InorderTree();

	BST->Remove(7);

	BST->InorderTree();

	BST->Remove(1);*/

	BST->InorderTree();
	char *temp = new char[5];
	
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}