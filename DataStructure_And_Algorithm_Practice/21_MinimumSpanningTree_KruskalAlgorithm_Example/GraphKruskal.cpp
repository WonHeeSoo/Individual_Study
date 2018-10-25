#include "GraphKruskal.h"
#include <iostream>
#include <stack>

GraphKruskal::GraphKruskal(int numVertex, int numEdge) : nVertex(numVertex), nEdge(numEdge)
{
	vertices = new Vertex[numVertex];
	for (int i = 0; i < numVertex; i++)
	{
		vertices[i].id = i;
	}
}


GraphKruskal::~GraphKruskal()
{
	if (vertices != NULL)
		delete[] vertices;
}

bool GraphKruskal::InsertEdge(int fromVertex, int toVertex, int weight)
{
	if (fromVertex < 0 || fromVertex >= nVertex)
		return false;
	if (toVertex < 0 || toVertex >= nVertex)
		return false;

	Edge edge{ fromVertex, toVertex, weight };
	vertices[fromVertex].edges.push_back(edge);
	priorityEdges.push(edge);
	nEdge++;
	return true;
}

bool GraphKruskal::RemoveEdge(int fromVertex, int toVertex, int weight)
{
	if (fromVertex < 0 || fromVertex >= nVertex)
		return false;
	if (toVertex < 0 || toVertex >= nVertex)
		return false;
	if (vertices[fromVertex].edges.empty() || vertices[toVertex].edges.empty())
		return false;

	const list<Edge> &edge = vertices[fromVertex].edges;

	list<Edge>::const_iterator it = edge.begin();
	for (; it != edge.end();)
	{
		if (it->endVertex == toVertex || it->weight == weight)
		{ // 도착하는 Vertex 위치가 같고, 무게가 같으면
			vertices[fromVertex].edges.erase(it);
			priorityEdges.pop();
			nEdge--;
			return true;
		}
		else
			it++;
	}

	return false;
}

bool GraphKruskal::ConnectVertices(int aVertex, int bVertex)
{
	if (aVertex < 0 || aVertex >= nVertex)
		return false;

	if (bVertex < 0 || bVertex >= nVertex)
		return false;

	if (vertices[aVertex].edges.empty() || vertices[bVertex].edges.empty())
		return false;

	ResetVisited();

	stack<int> vertexStack;
	vertexStack.push(aVertex);

	while (!vertexStack.empty())
	{
		Vertex &curVertex = vertices[vertexStack.top()];
		vertexStack.pop();

		if (&curVertex == &vertices[bVertex])
			return true;

		vertexStack.pop();

		if (curVertex.visited)
			continue;

		curVertex.visited = true;
		HandleVertex(curVertex);

		const list<Edge> &edges = curVertex.edges;

		list<Edge>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			if (!vertices[it->endVertex].visited)
				vertexStack.push(it->endVertex);
			//if (!vertices[*it].visited)
				//vertexStack.push(*it);
		}
	}

	ResetVisited();
	return false;
}

bool GraphKruskal::KruskalMST()
{
	list<Edge> restoreEdge;
	int vertexIndex = 0;

	while (nEdge + 1 != nVertex) // Edge + 1 == Vertex가 성립할때까지
	{
		if (nEdge - nVertex < -1) // Vertex가 하나라도 연결이 되어있지 않다면
			return false;

		// 우선순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다
		//Edge edge = priorityEdges.pop();
		Edge edge = priorityEdges.top();
		restoreEdge.push_back(priorityEdges.top());

		// 우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제한다
		priorityEdges.pop();
		//edge.pop()
		// 간선을 삭제하고 두 정점을 연결하는 경로가 있는지 확인한다 if
		if (!ConnectVertices(edge.startVertex, edge.endVertex)) // 연결하지 못했다면
			priorityEdges.push(restoreEdge.back());
		else
		{
			vertices[edge.startVertex].edges.erase()
		}
		// 경로가 없다면 삭제한 간선을 복원한다
		// 복원한 간선의 정보를 별도로 저장한다
	}
}

void GraphKruskal::HandleVertex(const Vertex & vertex)
{
	cout << "  . Visited vertex number : " << vertex.id << endl;
}

void GraphKruskal::ResetVisited()
{
	for (int i = 0; i < nVertex; i++)
		vertices[i].visited = false;
}
