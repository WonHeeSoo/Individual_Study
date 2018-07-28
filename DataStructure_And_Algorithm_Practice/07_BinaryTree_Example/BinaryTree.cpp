#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	rootNode = new TreeNode();
	rootNode->left = NULL;
	rootNode->right = NULL;
}

BinaryTree::~BinaryTree()
{
	DeleteNode(rootNode);
}

void BinaryTree::MakeLeftSubTree(TreeNode * bt)
{
	if (bt == NULL)
	{
		fprintf(stderr, "# Error: Empty Node.");
		return;
	}

	if (bt->left != NULL)
	{
		DeleteNode(bt->left);
	}

	TreeNode *newNode = new TreeNode();
	bt->left = newNode;
}

void BinaryTree::MakeRightSubTree(TreeNode * bt)
{
	if (bt == NULL)
	{
		fprintf(stderr, "# Error: Empty Node.");
		return;
	}

	if (bt->right != NULL)
	{
		DeleteNode(bt->right);
	}

	TreeNode *newNode = new TreeNode();
	bt->right = newNode;
}

// Tree node is first.
void BinaryTree::PreorderTraverse(TreeNode *bt)
{
	if (bt == NULL)
		return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

// Tree node is middle.
void BinaryTree::InorderTraverse(TreeNode *bt)
{
	if (bt == NULL)
		return;

	PreorderTraverse(bt->left);
	printf("%d ", bt->data);
	PreorderTraverse(bt->right);
}

// Tree node is last.
void BinaryTree::PostporderTraverse(TreeNode *bt)
{
	if (bt == NULL)
		return;

	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
	printf("%d ", bt->data);
}

void BinaryTree::DeleteNode(TreeNode * bt)
{
	if (bt == NULL)
		return;

	DeleteNode(bt->left);
	DeleteNode(bt->right);
	delete bt;
}

int BinaryTree::GetData(TreeNode * bt)
{
	if (bt == NULL)
		return ERROR;

	return bt->data;
}

TreeNode BinaryTree::GetNode(TreeNode * bt)
{
	if (bt == NULL)
	//	return NULL;
	return TreeNode();
}
