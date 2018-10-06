#include "AVLTree.h"



AVLTree::AVLTree() : rootNode(NULL)
{
}


AVLTree::~AVLTree()
{
	RemoveTree();
}

void AVLTree::Insert(data_t value)
{
	if (rootNode == NULL)
	{
		rootNode = new TreeNode(value);
		return;
	}

	TreeNode *iNode = rootNode;
	TreeNode *parentNode;
	TreeNode *grandParentNode;
	while (iNode != NULL)
	{
		if (value == iNode->value)
			// data의 같은 값을 허용하지 않음
			return;
		else if (value < iNode->value)
		{
			// data의 값이 더 작으면
			if (iNode->left == NULL)
			{
				iNode->left = new TreeNode(value);
				return;
			}
			grandParentNode = parentNode;
			parentNode = iNode;
			iNode = iNode->left;
		}
		else
		{
			// data의 값이 더 크면
			if (iNode->right == NULL)
			{
				iNode->right = new TreeNode(value);
				return;
			}
			iNode = iNode->right;
		}
	}

	Rebalance();
}

int AVLTree::GetHeightDiff(TreeNode * node)
{
	int leftValue, rightValue = 0;
	TreeNode *leftChildNode = node->left;
	TreeNode *rightChildNode = node->right;

	// 따로 while 해서 각각 도는게 효율적인지 같이 돌려도 되는지
	/*while (leftChildNode != NULL || rightChildNode != NULL)
	{
		if (leftChildNode != NULL)
		{
			leftValue++;
			leftChildNode = leftChildNode->left;
		}

		if (rightChildNode != NULL)
		{
			rightValue++;
			rightChildNode = rightChildNode->right;
		}
	}*/
	while (leftChildNode != NULL)
	{
		leftValue++;
		leftChildNode = leftChildNode->left;
	}

	while (rightChildNode != NULL)
	{
		rightValue++;
		rightChildNode = rightChildNode->right;
	}
	////////////////////////////////////////////////

	return (leftValue - rightValue);
}

void AVLTree::RotateLL(TreeNode * node)
{
	TreeNode *childNode = node->left;
	TreeNode *rightOfChildNode = childNode->right;
	
	childNode->right = node;
	node->left = rightOfChildNode;
	return;
}

void AVLTree::RotateRR(TreeNode * node)
{
	TreeNode *childNode = node->right;
	TreeNode *leftOfChildNode = childNode->left;

	childNode->left = node;
	node->left = leftOfChildNode;
	return;
}
