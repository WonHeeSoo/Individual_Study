#include "Graph.h"
#include "include\MyStackTemplate.h"
#include <iostream>

using namespace std;



Graph::Graph(int size) : graphSize(size), vertexCnt(0), edgeCnt(0), adjList(NULL)
{
	adjList = new LinkedList[size];
	for (int i = 0; i < size; i++)
	{
		adjList[i].SetHead(new Node(i));
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

bool Graph::DFS(int pos = 0)
{
	if (adjList[pos].GetHead() == NULL)
	{
		return false;
	}
	MyStackTemplate<Node*> stack;
	//Node *node = adjList[pos].GetHead();
	LinkedList *startList = &adjList[pos];
	LinkedList *searchList = startList;

	startList->GetHead()->visit = true;
	cout << "Pos : " << startList->GetHead()->pos << " ";
	stack.Push(startList->GetHead());
	if (startList->SearchNoVisitNode() == NULL)
	{// startList�� ����� ��尡 �ϳ��� ������
		return false;
	}

	searchList = &adjList[startList->SearchNoVisitNode()->pos];
	while (!(startList->GetTail()->visit == true && stack.IsEmpty() == true))
	{ // startList�� ������ �湮�߰�, stack�� ��� �ֱ� ������
		
		if (searchList->GetHead()->visit == true) // �湮�� ��ġ�� �̹� �湮�ߴٸ�
		{
			while (searchList->GetHead()->visit == true || startList->GetTail()->visit == false) 
			{// �湮���� ���� ���� ã�ų� startList�� ������ �湮���� �ʾ���������
				searchList = &adjList[stack.Pop()->pos];
				if (searchList->SearchNoVisitNode() != NULL) // �� ��尡 �ƴϸ�
				{
					searchList = &adjList[searchList->SearchNoVisitNode()->pos];
				}
			}
			//searchList = &adjList[searchList->SearchNoVisitNode()->pos]
		}
		
		// �湮��(list) ��� Ʈ���ϱ�
	}

	ResetSearch();
}

bool Graph::BFS()
{
	ResetSearch();
	return true;
}

