#include "UndirectedGraphKruskal.h"
#include <iostream>
#include <stack>

const int Edge::INVALID_ID = -1;
const int Vertex::INVALID_ID = Edge::INVALID_ID;


bool Edge::operator<(const Edge &r_val) const
{
	if (weight < r_val.weight)
		return true;
	else
		return false;
}

UndirectedGraphKruskal::UndirectedGraphKruskal(int numVertex) : nVertex(numVertex)
{
	vertices = new Vertex[numVertex];
	for (int i = 0; i < numVertex; i++)
		vertices[i].id = i;

	allEdges = new list<Edge>[numVertex];
}

UndirectedGraphKruskal::~UndirectedGraphKruskal()
{
	if (vertices != NULL)
		delete[] vertices;

	if (allEdges != NULL)
		delete[] allEdges;
}

bool UndirectedGraphKruskal::InsertEdge(int aNode, int bNode, double weight)
{
	if (aNode < 0 || aNode >= nVertex)
		return false;
	if (bNode < 0 || bNode >= nVertex)
		return false;
	if (aNode == bNode)
		return false;

	Edge aEdge{ aNode, bNode, weight };
	allEdges[aNode].push_back(aEdge);

	Edge bEdge{ bNode, aNode, weight };
	allEdges[bNode].push_back(bEdge);

	nEdge++;
	return true;
}

bool UndirectedGraphKruskal::RemoveEdge(int aNode, int bNode, double weight)
{
	if (aNode < 0 || aNode >= nVertex)
		return false;
	if (bNode < 0 || bNode >= nVertex)
		return false;
	if (aNode == bNode)
		return false;
	if (allEdges[aNode].empty())
		return false;

	const list<Edge> &aEdge = allEdges[aNode];
	
	list<Edge>::const_iterator aIt;
	for (aIt = aEdge.begin(); aIt != aEdge.end();)
	{
		if (aIt->endVertex == bNode || aIt->weight == weight)
		{ // 도착하는 Vertex 위치가 같고, 무게가 같으면
			allEdges[aNode].erase(aIt);
			break;
		}
		else
		{
			aIt++;
		}
	}

	const list<Edge> &bEdge = allEdges[bNode];

	list<Edge>::const_iterator bIt;
	for (bIt = bEdge.begin(); bIt != bEdge.end();)
	{
		if (bIt->endVertex == aNode || bIt->weight == weight)
		{ // 도착하는 Vertex 위치가 같고, 무게가 같으면
			allEdges[bNode].erase(bIt);
			nEdge--;
			return true;
		}
		else
		{
			bIt++;
		}
	}

	return false;
}

bool UndirectedGraphKruskal::IsConnected(int aNode, int bNode)
{
	if (aNode < 0 || aNode >= nVertex)
		return false;

	if (bNode < 0 || bNode >= nVertex)
		return false;

	if (allEdges[aNode].empty())
		return false;

	ResetVisited();

	stack<int> vertexStack;
	vertexStack.push(aNode);

	while (!vertexStack.empty())
	{
		Vertex &curVertex = vertices[vertexStack.top()];
		vertexStack.pop();

		if (curVertex.id == vertices[bNode].id)
			return true;


		curVertex.visited = true;
		HandleVertex(curVertex);

		const list<Edge> &edges = allEdges[curVertex.id];

		list<Edge>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			if (!vertices[it->endVertex].visited)
				vertexStack.push(it->endVertex);
		}
	}

	ResetVisited();
	return false;
}

bool UndirectedGraphKruskal::BuildSpanningTree()
{
	PrintAllEdges();

	list<Edge> restoreEdges;
	priority_queue<Edge> priorityEdges;
	int vertexIndex = 0;

	for (int i = 0; i < nVertex; i++) // weight 우선순위로 담기
	{
		const list<Edge> &edges = allEdges[i];

		list<Edge>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			priorityEdges.push(*it);
		}
	}

	while (!priorityEdges.empty())
	{
		if ((nVertex - nEdge) > 1) // Vertex가 하나라도 연결이 되어있지 않다면
			return false;

		// priorityEdges에서 가중치가 제일 높은 Edge의 정보를 꺼낸다
		Edge heavyEdge = priorityEdges.top();
		restoreEdges.push_back(heavyEdge);
		priorityEdges.pop(); // Undirected
		priorityEdges.pop();

		// priorityEdges에서 꺼낸 Edge를 실제로 그래프에서 삭제한다
		RemoveEdge(heavyEdge.startVertex, heavyEdge.endVertex, heavyEdge.weight);

		// Edge를 삭제하고 두 Vertex를 연결하는 경로가 있는지 확인한다
		if (!IsConnected(heavyEdge.startVertex, heavyEdge.endVertex)) // 연결하지 못했다면
		{
			InsertEdge(restoreEdges.back().startVertex, restoreEdges.back().endVertex, restoreEdges.back().weight);
			restoreEdges.pop_back();
		}
	}
	PrintAllEdges();

	return true;
}

void UndirectedGraphKruskal::PrintAllEdges()
{
	for (int i = 0; i < nVertex; i++)
	{
		const list<Edge> &edges = allEdges[i];

		list<Edge>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			cout << "vertices[" << i << "] : " << it->startVertex
				<< " / " << it->endVertex
				<< " / " << it->weight << endl;
		}
	}
	cout << endl;
}


void UndirectedGraphKruskal::HandleVertex(const Vertex &vertex)
{
	cout << "  . Visited vertex number : " << vertex.id << endl;
}

void UndirectedGraphKruskal::ResetVisited()
{
	for (int i = 0; i < nVertex; i++)
		vertices[i].visited = false;
}
