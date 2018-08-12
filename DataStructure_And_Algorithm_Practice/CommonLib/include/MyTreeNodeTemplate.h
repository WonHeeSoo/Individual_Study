#pragma once


template <typename T>
struct TreeNode
{
	T			data;
	TreeNode<T>	*left;
	TreeNode<T>	*right;

	TreeNode<T>(T data) : data(data), left(NULL), right(NULL) {}
	TreeNode<T>() : left(NULL), right(NULL) {}

	// Making left node.
	TreeNode<T>* AddLeftChild(T data);
	// Making right node.
	TreeNode<T>* AddRightChild(T data);

	static void DeleteNode(TreeNode<T> *bt);
};


template <typename T>
TreeNode<T>* TreeNode<T>::AddLeftChild(T data)
{
	if (bt->left != NULL)
		DeleteNode(bt->left);
	TreeNode *newNode = new TreeNode(data);
	bt->left = newNode;
	return newNode;
}

template <typename T>
TreeNode<T>* TreeNode<T>::AddRightChild(T data)
{
	if (bt->right != NULL)
		DeleteNode(bt->right);
	TreeNode *newNode = new TreeNode(data);
	bt->right = newNode;
	return newNode;
}

template <typename T>
void TreeNode<T>::DeleteNode(TreeNode<T> * bt)
{
	if (bt == NULL)
		return;

	DeleteNode(bt->left);
	DeleteNode(bt->right);
	delete bt;
}
