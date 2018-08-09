#pragma once
#include <stdio.h>

template <typename T>
struct TreeNode
{
	T			data;
	TreeNode	*left;
	TreeNode	*right;

	TreeNode<T>(T data) : data(data), left(NULL), right(NULL) {}
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree<T>(T data);
	virtual ~BinaryTree<T>();

	// Making left node.
	TreeNode<T>* MakeLeftSubTree(TreeNode<T> *bt, T data);
	// Making right node.
	TreeNode<T>* MakeRightSubTree(TreeNode<T> *bt, T data);

	void PreorderTree();
	void InorderTree();
	void PostorderTree();

	void DepthOrderTree();
	

	void DeleteNode(TreeNode<T> *bt);

	inline TreeNode<T> *GetRootNode() { return rootNode; }

	T GetData(TreeNode<T> *bt);

	void SetData(TreeNode<T> *bt, T data);

	TreeNode<T> GetNode(TreeNode<T> *bt);
	TreeNode<T> GetLeftSubTree(TreeNode<T> *bt);
	TreeNode<T> GetRightSubTree(TreeNode<T> *bt);


	//inline void SetData()
	static const int ERROR = -1;
private:
	TreeNode<T>	*rootNode;

	// Root node is first.
	void PreorderTraverse(TreeNode<T> *bt);
	// Root node is middle.
	void InorderTraverse(TreeNode<T> *bt);
	// Root node is last.
	void PostporderTraverse(TreeNode<T> *bt);
};

template <typename T>
BinaryTree<T>::BinaryTree(T data)
{
	rootNode = new TreeNode(data);
	rootNode->left = NULL;
	rootNode->right = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	DeleteNode(rootNode);
}

template <typename T>
TreeNode<T>* BinaryTree<T>::MakeLeftSubTree(TreeNode<T> *bt, T data)
{
	if (bt->left != NULL)
	{
		DeleteNode(bt->left);
	}
	TreeNode *newNode = new TreeNode(data);
	bt->left = newNode;
	return newNode;
}

template <typename T>
TreeNode<T>* BinaryTree<T>::MakeRightSubTree(TreeNode<T> *bt, T data)
{
	if (bt->right != NULL)
	{
		DeleteNode(bt->right);
	}

	TreeNode *newNode = new TreeNode(data);
	bt->right = newNode;
	return newNode;
}

template <typename T>
void BinaryTree<T>::PreorderTree() {
	printf("Preorder  : ");
	PreorderTraverse(rootNode);
	printf("\n");
}

template <typename T>
void BinaryTree<T>::InorderTree() {
	printf("Inorder   : ");
	InorderTraverse(rootNode);
	printf("\n");
}

template <typename T>
void BinaryTree<T>::PostorderTree() {
	printf("Postorder : ");
	PostporderTraverse(rootNode);
	printf("\n");
}

template <typename T>
void BinaryTree<T>::DepthOrderTree()
{
	std::list<TreeNode<T>*> visit_queue;

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
template <typename T>
void BinaryTree<T>::PreorderTraverse(TreeNode<T> *bt)
{
	if (bt == NULL)
		return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

// Tree node is middle.
template <typename T>
void BinaryTree<T>::InorderTraverse(TreeNode<T> *bt)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}

// Tree node is last.
template <typename T>
void BinaryTree<T>::PostporderTraverse(TreeNode<T> *bt)
{
	if (bt == NULL)
		return;

	PostporderTraverse(bt->left);
	PostporderTraverse(bt->right);
	printf("%d ", bt->data);
}

template <typename T>
void BinaryTree<T>::DeleteNode(TreeNode<T> * bt)
{
	if (bt == NULL)
		return;

	DeleteNode(bt->left);
	DeleteNode(bt->right);
	delete bt;
}

template <typename T>
T BinaryTree<T>::GetData(TreeNode<T> * bt)
{
	if (bt == NULL)
		return ERROR;

	return bt->data;
}

template <typename T>
void BinaryTree<T>::SetData(TreeNode<T> * bt, T data)
{
	bt->data = data;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::GetNode(BinaryTree<T> *bt)
{
	if (bt == NULL)
		return TreeNode();

	return bt->data;
}