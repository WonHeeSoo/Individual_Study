#include "BinarySearchTree.h"
#include <list>


BinarySearchTree::BinarySearchTree(size_t data) : rootNode(NULL)
{
	rootNode = new TreeNode();
	rootNode->data = data;
	rootNode->left = NULL;
	rootNode->right = NULL;
}


BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::Insert(size_t data)
{
	TreeNode *iNode = rootNode;
	while (iNode != NULL)
	{
		// �������� �ߺ��� ������� ����
		if (data == iNode->data)
			return;

		if (iNode->data > data)
		{
			if (iNode->left == NULL)
			{
				TreeNode *lNode = new TreeNode(data);
				iNode->left = lNode;
				return;
			}
			iNode = iNode->left;
		}
		else
		{
			if (iNode->right == NULL)
			{
				TreeNode *lNode = new TreeNode(data);
				iNode->right = lNode;
				return;
			}
			iNode = iNode->right;
		}
	}
}

TreeNode* BinarySearchTree::Search(size_t target)
{
	TreeNode *sNode = rootNode;

	while (sNode != NULL)
	{
		if (sNode->data == target)
			return sNode;
		else if (sNode->data > target)
			sNode = sNode->left;
		else
			sNode = sNode->right;
	}

	return NULL;
}

size_t BinarySearchTree::Remove(size_t target)
{
	if (rootNode == NULL)
		return NULL;

	TreeNode *dNode = rootNode;
	TreeNode *tParentNode = NULL;

	while (dNode->data != target)
	{
		if (dNode != NULL)
		{
			tParentNode = dNode;
			if (dNode->data < target)
				dNode = dNode->right;
			else
				dNode = dNode->left;
		}
		else
			return NULL;
		
	}

	size_t result = dNode->data;

	// �ڽ� ��尡 ���ٸ�
	if (dNode->left == NULL && dNode->right == NULL)
	{
		delete dNode;
		return result;
	}
	// ������ �ڽ� ��尡 ������
	else if (dNode->right == NULL)
	{
		TreeNode *leftChildNode = dNode->left;

		// rootNode�� ���
		if (tParentNode == NULL)
		{
			delete dNode;
			rootNode = leftChildNode;
		}
		else
		{
			delete dNode;
			tParentNode->left = leftChildNode;
		}

		return result;
	}
	// ���� �ڽ� ��尡 ������
	else if (dNode->left == NULL)
	{
		TreeNode *rightChildNode = dNode->right;

		delete dNode;

		// rootNode�� ���
		if (tParentNode == NULL)
			rootNode = rightChildNode;
		else
			tParentNode->left = rightChildNode;

		return result;
	}
	// ���� ������ �ڽ� ��尡 �ִٸ�
	else
	{
		TreeNode *childNode = dNode->right;
		TreeNode *pNode = dNode;
		while (childNode->left != NULL)
		{
			pNode = childNode;
			childNode = childNode->left;
		}

		// ������ ��带 ��ü�� ��忡 ������ �ڽ� ��尡 �ִٸ�
		if (childNode->right != NULL)
			pNode->right = childNode->right;
		else
			pNode->right = NULL;

		childNode->left = pNode->left;
		childNode->right = pNode->right;

		// dNode�� rootNode�� �ƴϸ�
		if (tParentNode != NULL)
		{
			// �θ� ����� �����ͺ��� ũ��
			if (dNode->data > tParentNode->data)
				tParentNode->right = childNode;
			else
				tParentNode->left = childNode;
		}

		delete dNode;
		
		return result;
	}
}

void BinarySearchTree::DepthOrderTree()
{
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
}

void BinarySearchTree::PreorderTree()
{
	printf("Preorder  : ");
	PreorderTraverse(rootNode);
	printf("\n");
}

void BinarySearchTree::InorderTree()
{
	printf("Inorder   : ");
	InorderTraverse(rootNode);
	printf("\n");
}

void BinarySearchTree::PostorderTree()
{
	printf("Postorder : ");
	PostporderTraverse(rootNode);
	printf("\n");
}

void BinarySearchTree::PreorderTraverse(TreeNode * bt)
{
	if (bt == NULL)
		return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void BinarySearchTree::InorderTraverse(TreeNode * bt)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}

void BinarySearchTree::PostporderTraverse(TreeNode * bt)
{
	if (bt == NULL)
		return;

	PostporderTraverse(bt->left);
	PostporderTraverse(bt->right);
	printf("%d ", bt->data);
}

// http://mattlee.tistory.com/30