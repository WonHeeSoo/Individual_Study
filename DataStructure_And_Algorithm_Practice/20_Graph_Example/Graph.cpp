#include "Graph.h"
#include "include\MyStackTemplate.h"
#include <iostream>

using namespace std;



Graph::Graph(int size) : graphSize(size), vertexCnt(0), edgeCnt(0), adjList(NULL)
{
	adjList = new LinkedList[size];
	for (int i = 0; i < size; i++)
	{
		adjList[i].Insert(i);
	}
}


Graph::~Graph()
{
	delete[] adjList;
}

bool Graph::Insert(int fromPos, int toPos)
{
	if (adjList[fromPos].GetHead() == NULL || adjList[toPos].GetHead() == NULL)
		// fromPos�� toPos�� ��ġ�� ������ ���ٸ�
		return false;

	adjList[fromPos].Insert(toPos);
	return true;
}

bool Graph::DFS(int pos)
{
	if (adjList[pos].GetHead() == NULL || adjList[pos].GetHead()->next == NULL)// ó�� ��ġ�� �������� �ʰ�, ó�� ��ġ���� ����� ��尡 ������
		return false;
	
	MyStackTemplate<Node*> stack;
	Node *node = adjList[pos].GetHead();

	cout << "/Pos : " << node->pos << ",      ";

	while (!(adjList[pos].GetTail()->check == true && stack.IsEmpty() == true))
	{ // startList�� ������ �湮�߰� stack�� �ƹ��͵� ���ٸ� 
		
		if (node == NULL || adjList[node->pos].GetVisit() == true)
		{ // node�� NULL �̰ų� �̹� �ش� ������ �湮 �ߴٸ�
			if (node != NULL && node->check == false) // node�� NULL�� �ƴϰ� �ش� �������� �湮������ ����� node�� check�� false��
				node->check = true;

			if (stack.IsEmpty() == false)
			{ // stack�� ������� �ʴٸ�
				node = stack.Pop();
				cout << "/fPos : " << node->pos << ",     ";
				if (adjList[node->pos].SearchNoVisitNode() != NULL)
				{ // �湮 
					stack.Push(node);
					node = adjList[node->pos].SearchNoVisitNode();
					cout << "/sPos : " << node->pos << ",     ";
				}
			}
		}
		else
		{ // �湮���� ���� ���̸�
			node->check = true;
			adjList[node->pos].SetVisit(true);

			stack.Push(node);

			if (node->next != NULL) // node�� next�� NULL�� �ƴϸ�
			{
				
				node = adjList[node->next->pos].GetHead();
				cout << "/tPos : " << node->pos << ",     ";
			}
			/*else
			{
				if (stack.IsEmpty() == false)
				{
					node = stack.Pop();
					cout << "/foPos : " << node->pos << ",     ";
				}
					
			}*/
				
		}
		//cout << "Pos : " << node->pos << ", ";
		
	}

	//ResetSearch();
	return true;
}

bool Graph::BFS()
{
	ResetSearch();
	return true;
}

void Graph::ShowGraph() const
{
}

void Graph::ResetSearch()
{
}

