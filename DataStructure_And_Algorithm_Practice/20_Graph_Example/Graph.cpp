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
		// fromPos나 toPos에 위치한 정점이 없다면
		return false;

	adjList[fromPos].Insert(toPos);
	return true;
}

bool Graph::DFS(int pos)
{
	if (adjList[pos].GetHead() == NULL || adjList[pos].GetHead()->next == NULL)
	{// 처음 위치가 존재하지 않고, 처음 위치에서 연결된 노드가 없으면
		return false;
	}
	MyStackTemplate<Node*> stack;
	//Node *node = adjList[pos].GetHead();
	LinkedList *startList = &adjList[pos];
	LinkedList *searchList = startList;

	while (!(startList->GetTail()->visit == true && stack.IsEmpty() == true))
	{ // startList의 꼬리에 방문했고 stack에 아무것도 없다면 
		if (searchList->GetHead()->visit == true)
		{// 이미 방문한 곳이면
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
	{// startList와 연결된 노드가 하나도 없으면
		return false;
	}

	searchList = &adjList[startList->SearchNoVisitNode()->pos];
	while (!(startList->GetTail()->visit == true && stack.IsEmpty() == true))
	{ // startList의 꼬리에 방문했고, stack이 비어 있기 전까지
		
		if (searchList->GetHead()->visit == true) // 방문한 위치에 이미 방문했다면
		{
			//while (searchList->GetHead()->visit == false) //|| startList->GetTail()->visit == false) 
			//{// 방문하지 않은 곳을 찾거나 startList의 꼬리에 방문하지 않았을때까지
				if (stack.IsEmpty() == false)
					searchList = &adjList[stack.Pop()->pos];
				
				if (searchList->SearchNoVisitNode() != NULL) // 빈 노드가 아니면
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
		{// searchList에 방문하지 않은 node가 있다면
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

