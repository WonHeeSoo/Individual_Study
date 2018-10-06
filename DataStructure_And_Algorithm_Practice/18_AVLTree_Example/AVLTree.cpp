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
			// data�� ���� ���� ������� ����
			return;
		else if (value < iNode->value)
		{
			// data�� ���� �� ������
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
			// data�� ���� �� ũ��
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

	// ���� while �ؼ� ���� ���°� ȿ�������� ���� ������ �Ǵ���
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
