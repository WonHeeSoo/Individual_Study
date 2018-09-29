#include "BinaryTree.h"
#include <list>


BinaryTree::BinaryTree(DType data)
{
	rootNode = new TreeNode(data);
	rootNode->left = NULL;
	rootNode->right = NULL;
}

BinaryTree::~BinaryTree()
{
	DeleteNode(rootNode);
}

TreeNode* BinaryTree::MakeLeftSubTree(TreeNode *bt, int data)
{
	if (bt->left != NULL)
	{
		DeleteNode(bt->left);
	}
	TreeNode *newNode = new TreeNode(data);
	bt->left = newNode;
	return newNode;
}

TreeNode* BinaryTree::MakeRightSubTree(TreeNode *bt, int data)
{
	if (bt->right != NULL)
	{
		DeleteNode(bt->right);
	}

	TreeNode *newNode = new TreeNode(data);
	bt->right = newNode;
	return newNode;
}

void BinaryTree::PreorderTree() {
	printf("Preorder  : ");
	PreorderTraverse(rootNode);
	printf("\n");
}
void BinaryTree::InorderTree() {
	printf("Inorder   : ");
	InorderTraverse(rootNode);
	printf("\n");
}
void BinaryTree::PostorderTree() {
	printf("Postorder : ");
	PostporderTraverse(rootNode);
	printf("\n");
}

void BinaryTree::DepthOrderTree()
{
	std::list<TreeNode*> visit_queue;

	printf("DepthOrder : ");

	visit_queue.push_back(rootNode);
	while (!visit_queue.empty()) {
		TreeNode	*cur_node = visit_queue.front();
		visit_queue.pop_front();

		printf("%d ", cur_node->data);
		if (cur_node->left)
			visit_queue.push_back(cur_node->left);
		if (cur_node->right)
			visit_queue.push_back(cur_node->right);
	}
	printf("\n");
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

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}

// Tree node is last.
void BinaryTree::PostporderTraverse(TreeNode *bt)
{
	if (bt == NULL)
		return;

	PostporderTraverse(bt->left);
	PostporderTraverse(bt->right);
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

void BinaryTree::SetData(TreeNode * bt, int data)
{
	bt->data = data;
}

TreeNode BinaryTree::GetNode(TreeNode * bt)
{
	if (bt == NULL)
		//	return NULL;
		return TreeNode();
}