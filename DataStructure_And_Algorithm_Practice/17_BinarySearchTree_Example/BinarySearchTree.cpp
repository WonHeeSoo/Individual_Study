#include "BinarySearchTree.h"
#include <list>


BinarySearchTree::BinarySearchTree() : rootNode(NULL)
{
}


BinarySearchTree::~BinarySearchTree()
{
	RemoveTree();
}

void BinarySearchTree::Insert(data_t data)
{
	if (rootNode == NULL)
	{
		rootNode = new TreeNode(data);
		return;
	}

	TreeNode *iNode = rootNode;
	while (iNode != NULL)
	{
		if (data == iNode->data)
			// data의 같은 값을 허용하지 않음
			return;
		else if (data < iNode->data)
		{
			// data의 값이 더 작으면
			if (iNode->left == NULL)
			{
				iNode->left = new TreeNode(data);
				return;
			}
			iNode = iNode->left;
		}
		else
		{
			// data의 값이 더 크면
			if (iNode->right == NULL)
			{
				iNode->right = new TreeNode(data);
				return;
			}
			iNode = iNode->right;
		}
	}
}

TreeNode* BinarySearchTree::Search(data_t target) const
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

bool BinarySearchTree::Remove(data_t target)
{
	if (rootNode == NULL)
		return false;

	TreeNode *dNode = rootNode;
	TreeNode *tParentNode = NULL;

	while (dNode != NULL)
	{
		if (target == dNode->data)
			break;

		tParentNode = dNode;
		if (target < dNode->data)
			dNode = dNode->left;
		else
			dNode = dNode->right;
	}

	if (dNode == NULL)
		return false;

	// 자식 노드가 없다면
	if (dNode->left == NULL && dNode->right == NULL)
		UpdateParent(tParentNode, dNode, NULL);
	// 오른쪽 자식 노드가 없으면
	else if (dNode->right == NULL)
		UpdateParent(tParentNode, dNode, dNode->left);
	// 왼쪽 자식 노드가 없으면
	else if (dNode->left == NULL)
		UpdateParent(tParentNode, dNode, dNode->right);
	// 왼쪽 오른쪽 자식 노드가 있다면
	else
	{
		TreeNode *childNode = dNode->right;
		TreeNode *pNode = dNode;
		while (childNode->left != NULL)
		{
			pNode = childNode;
			childNode = childNode->left;
		}

		// 삭제할 노드를 대체할 노드에 오른쪽 자식 노드가 있다면
		if (childNode->right != NULL)
			pNode->left = childNode->right;
		else
			pNode->left = NULL;

		childNode->left = dNode->left;
		childNode->right = dNode->right;

		
		UpdateParent(tParentNode, dNode, childNode);
	}

	delete dNode;
	return true;
}

void BinarySearchTree::DepthOrderTree() const
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

void BinarySearchTree::PreorderTree() const
{
	printf("Preorder  : ");
	PreorderTraverse(rootNode);
	printf("\n");
}

void BinarySearchTree::InorderTree() const
{
	printf("Inorder   : ");
	InorderTraverse(rootNode);
	printf("\n");
}

void BinarySearchTree::PostorderTree() const
{
	printf("Postorder : ");
	PostporderTraverse(rootNode);
	printf("\n");
}

void BinarySearchTree::PreorderTraverse(TreeNode * bt) const
{
	if (bt == NULL)
		return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void BinarySearchTree::InorderTraverse(TreeNode * bt) const
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}

void BinarySearchTree::PostporderTraverse(TreeNode * bt) const
{
	if (bt == NULL)
		return;

	PostporderTraverse(bt->left);
	PostporderTraverse(bt->right);
	printf("%d ", bt->data);
}

void BinarySearchTree::RemoveTree()
{
	if (rootNode == NULL)
		return;

	InorderTraverse(rootNode->left);
	InorderTraverse(rootNode->right);
}


void BinarySearchTree::UpdateParent(TreeNode *parent, TreeNode *toBeDeleted, TreeNode *newChild)
{
	if (parent == NULL)
		// 'targetNode' is the root
		rootNode = newChild;
	else if (toBeDeleted == parent->left)
		parent->left = newChild;
	else
		parent->right = newChild;
}


// http://mattlee.tistory.com/30