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
	if (adjList[pos].GetHead() == NULL || adjList[pos].GetHead()->next == NULL)// 처음 위치가 존재하지 않고, 처음 위치에서 연결된 노드가 없으면
		return false;
	
	MyStackTemplate<Node*> stack;
	Node *node = adjList[pos].GetHead();

	cout << "/Pos : " << node->pos << ",      ";

	while (!(adjList[pos].GetTail()->check == true && stack.IsEmpty() == true))
	{ // startList의 꼬리에 방문했고 stack에 아무것도 없다면 
		
		if (node == NULL || adjList[node->pos].GetVisit() == true)
		{ // node가 NULL 이거나 이미 해당 정점에 방문 했다면
			if (node != NULL && node->check == false) // node가 NULL이 아니고 해당 정점에는 방문했지만 연결된 node의 check가 false면
				node->check = true;

			if (stack.IsEmpty() == false)
			{ // stack이 비어있지 않다면
				node = stack.Pop();
				cout << "/fPos : " << node->pos << ",     ";
				if (adjList[node->pos].SearchNoVisitNode() != NULL)
				{ // 방문 
					stack.Push(node);
					node = adjList[node->pos].SearchNoVisitNode();
					cout << "/sPos : " << node->pos << ",     ";
				}
			}
		}
		else
		{ // 방문하지 않은 곳이면
			node->check = true;
			adjList[node->pos].SetVisit(true);

			stack.Push(node);

			if (node->next != NULL) // node의 next가 NULL이 아니면
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

