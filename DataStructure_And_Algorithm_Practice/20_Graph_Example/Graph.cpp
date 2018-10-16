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
		// fromPos나 toPos에 위치한 정점이 없다면
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
	{// startList와 연결된 노드가 하나도 없으면
		return false;
	}

	searchList = &adjList[startList->SearchNoVisitNode()->pos];
	while (!(startList->GetTail()->visit == true && stack.IsEmpty() == true))
	{ // startList의 꼬리에 방문했고, stack이 비어 있기 전까지
		
		if (searchList->GetHead()->visit == true) // 방문한 위치에 이미 방문했다면
		{
			while (searchList->GetHead()->visit == true || startList->GetTail()->visit == false) 
			{// 방문하지 않은 곳을 찾거나 startList의 꼬리에 방문하지 않았을때까지
				searchList = &adjList[stack.Pop()->pos];
				if (searchList->SearchNoVisitNode() != NULL) // 빈 노드가 아니면
				{
					searchList = &adjList[searchList->SearchNoVisitNode()->pos];
				}
			}
			//searchList = &adjList[searchList->SearchNoVisitNode()->pos]
		}
		
		// 방문지(list) 헤드 트루하기
	}

	ResetSearch();
}

bool Graph::BFS()
{
	ResetSearch();
	return true;
}

