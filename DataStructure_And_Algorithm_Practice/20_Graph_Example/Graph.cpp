#include "Graph.h"
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

const int Vertex::INVALID_ID = -1;

Graph::Graph(int numVertex) : nVertex(numVertex)
{
	vertices = new Vertex[numVertex];
	for (int i = 0; i < numVertex; i++)
	{
		vertices[i].id = i;
	}
}


Graph::~Graph()
{
	if (vertices != NULL)
		delete[] vertices;
}

bool Graph::InsertEdge(int fromVertex, int toVertex)
{
	if (fromVertex < 0 || fromVertex >= nVertex)
		return false;
	if (toVertex < 0 || toVertex >= nVertex)
		return false;

	vertices[fromVertex].edges.push_back(toVertex);
	return true;
}

bool Graph::DFS(int startVertex)
{
	if (startVertex < 0 || startVertex >= nVertex)
		return false;

	if (vertices[startVertex].edges.empty())
		return true;

	ResetVisited();

	stack<int> vertexStack;
	vertexStack.push(startVertex);

	while (!vertexStack.empty())
	{
		Vertex &curVertex = vertices[vertexStack.top()];
		vertexStack.pop();

		if (curVertex.visited)
			continue;
		
		curVertex.visited = true;
		HandleVertex(curVertex);

		const list<int>	&edges = curVertex.edges;

		list<int>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			if (!vertices[*it].visited)
				vertexStack.push(*it);
		}
	}
	return true;
}

bool Graph::BFS(int startVertex)
{
	if (startVertex < 0 || startVertex >= nVertex)
		return false;

	if (vertices[startVertex].edges.empty())
		return true;

	ResetVisited();

	queue<int> vertexQueue;
	vertexQueue.push(startVertex);

	while (!vertexQueue.empty())
	{
		Vertex &curVertex = vertices[vertexQueue.front()];
		vertexQueue.pop();

		if (curVertex.visited)
			continue;

		curVertex.visited = true;
		HandleVertex(curVertex);

		const list<int>	&edges = curVertex.edges;

		list<int>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			if (!vertices[*it].visited)
				vertexQueue.push(*it);
		}
	}
	return true;
}

void Graph::ShowGraph() const
{
}

void Graph::HandleVertex(const Vertex &vertex)
{
	cout << "  . Visited vertex number : " << vertex.id << endl;
}

void Graph::ResetVisited()
{
	for (int i = 0; i < nVertex; i++)
		vertices[i].visited = false;
}

