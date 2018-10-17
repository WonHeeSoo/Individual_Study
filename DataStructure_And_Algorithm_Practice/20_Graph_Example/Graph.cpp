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
	if (adjList[pos].GetHead() == NULL || adjList[pos].GetHead()->next == NULL)
	{// ó�� ��ġ�� �������� �ʰ�, ó�� ��ġ���� ����� ��尡 ������
		return false;
	}
	MyStackTemplate<Node*> stack;
	//Node *node = adjList[pos].GetHead();
	LinkedList *startList = &adjList[pos];
	LinkedList *searchList = startList;

	while (!(startList->GetTail()->visit == true && stack.IsEmpty() == true))
	{ // startList�� ������ �湮�߰� stack�� �ƹ��͵� ���ٸ� 
		if (searchList->GetHead()->visit == true)
		{// �̹� �湮�� ���̸�
			if (stack.IsEmpty() == false)
				searchList = &adjList[stack.Pop()->pos];

			//searchList = &adjList[searchList->SearchNoVisitNode()->pos];
		}
		else
		{
			searchList->GetHead()->visit = true;
			cout << "Pos : " << searchList->GetHead()->pos << " / ";
			stack.Push(searchList->GetHead());
		}
		
		searchList = &adjList[searchList->SearchNoVisitNode()->pos];
	}
	


	/*startList->GetHead()->visit = true;
	cout << "Pos : " << startList->GetHead()->pos << " / ";
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
			//while (searchList->GetHead()->visit == false) //|| startList->GetTail()->visit == false) 
			//{// �湮���� ���� ���� ã�ų� startList�� ������ �湮���� �ʾ���������
				if (stack.IsEmpty() == false)
					searchList = &adjList[stack.Pop()->pos];
				
				if (searchList->SearchNoVisitNode() != NULL) // �� ��尡 �ƴϸ�
					searchList = &adjList[searchList->SearchNoVisitNode()->pos];
			//}
		}
		
		if (searchList->GetHead()->visit == false)
		{
			searchList->GetHead()->visit = true;
			cout << "Pos : " << startList->GetHead()->pos << " ";
			stack.Push(searchList->GetHead());
		}
		
		if (searchList->SearchNoVisitNode() != NULL)
		{// searchList�� �湮���� ���� node�� �ִٸ�
			searchList = &adjList[searchList->SearchNoVisitNode()->pos];
		}
	}*/

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

