#include "BinarySearchTree.h"

// 랜덤 값 만들기
// 제거 함수 만들기

int main()
{
	BinarySearchTree *BST = new BinarySearchTree();

	BST->Insert(1);
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

	BST->Remove(1);

	BST->InorderTree();
	return 0;
}