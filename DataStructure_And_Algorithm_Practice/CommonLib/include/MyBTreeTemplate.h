#pragma once
#include <stdio.h>
#include "MyTreeNodeTemplate.h"

template <typename T>
class MyBinaryTreeTemplate
{
public:
	MyBinaryTreeTemplate<T>(T data);
	MyBinaryTreeTemplate<T>();
	virtual ~MyBinaryTreeTemplate<T>();

	void PreorderTree();
	void InorderTree();
	void PostorderTree();

	void DepthOrderTree();
	
	// Root node is first.
	void PreorderTraverse(TreeNode<T> *bt);
	// Root node is middle.
	void InorderTraverse(TreeNode<T> *bt);
	// Root node is last.
	void PostporderTraverse(TreeNode<T> *bt);

	inline TreeNode<T> *GetRootNode() { return rootNode; }
	void SetRootNode(TreeNode<T> *bt);

	//inline void SetData()
	static const int ERROR = -1;
private:
	TreeNode<T>	*rootNode;

};

template <typename T>
MyBinaryTreeTemplate<T>::MyBinaryTreeTemplate(T data)
{
	rootNode = new TreeNode<T>(data);
	rootNode->left = NULL;
	rootNode->right = NULL;
}

template <typename T>
MyBinaryTreeTemplate<T>::MyBinaryTreeTemplate()
{
	rootNode = new TreeNode<T>();
	rootNode->left = NULL;
	rootNode->right = NULL;
}

template <typename T>
MyBinaryTreeTemplate<T>::~MyBinaryTreeTemplate()
{
	TreeNode<T>::DeleteNode(rootNode);
}

template <typename T>
void MyBinaryTreeTemplate<T>::PreorderTree() {
	printf("Preorder  : ");
	PreorderTraverse(rootNode);
	printf("\n");
}

template <typename T>
void MyBinaryTreeTemplate<T>::InorderTree() {
	printf("Inorder   : ");
	InorderTraverse(rootNode);
	printf("\n");
}

template <typename T>
void MyBinaryTreeTemplate<T>::PostorderTree() {
	printf("Postorder : ");
	PostporderTraverse(rootNode);
	printf("\n");
}

/*template <typename T>
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
}*/

// Tree node is first.
template <typename T>
void MyBinaryTreeTemplate<T>::PreorderTraverse(TreeNode<T> *bt)
{
	if (bt == NULL)
		return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

// Tree node is middle.
template <typename T>
void MyBinaryTreeTemplate<T>::InorderTraverse(TreeNode<T> *bt)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}

// Tree node is last.
template <typename T>
void MyBinaryTreeTemplate<T>::PostporderTraverse(TreeNode<T> *bt)
{
	if (bt == NULL)
		return;

	PostporderTraverse(bt->left);
	PostporderTraverse(bt->right);
	printf("%d ", bt->data);
}

template <typename T>
void MyBinaryTreeTemplate<T>::SetRootNode(TreeNode<T> *bt)
{
	if (rootNode != NULL)
		TreeNode<T>::DeleteNode(rootNode);
	rootNode = bt;
}