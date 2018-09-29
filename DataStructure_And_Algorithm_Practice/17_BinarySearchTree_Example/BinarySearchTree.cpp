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
		// 데이터의 중복을 허용하지 않음
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
			return sNode->left;
		else
			return sNode->right;
	}

	return NULL;
}

size_t BinarySearchTree::Remove(size_t target)
{
	if (rootNode == NULL)
	{
		//return -1;
	}
	// root에 자식이 없는 단말 노드라면
	else if (rootNode->data == target && rootNode->left == NULL && rootNode->right == NULL)
	{
		size_t result = rootNode->data;
		delete rootNode;
		return result;
	}
	else
	{
		TreeNode *tNode = Search(target);
		size_t result = tNode->data;
		// 해당 노드에 자식 노드가 없으면
		if (tNode->left == NULL && tNode->right == NULL)
		{
			size_t result = tNode->data;
			delete tNode;
			return result;
		}
		else
		{
			if (tNode->right != NULL)
			{
				// 오른쪽 자식 노드의 왼쪽 자식 노드가 없다면
				if (tNode->right->left != NULL)
				{
					TreeNode *fNode = tNode;
					while (fNode->right == NULL)
					{
						fNode->right->left = fNode->left;
						fNode = fNode->right;
					}
				}
			}
			
		}
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