#include "GraphKruskal.h"
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

GraphKruskal::GraphKruskal(int numVertex) : nVertex(numVertex)
{
	vertices = new Vertex[numVertex];
	for (int i = 0; i < numVertex; i++)
		vertices[i].id = i;
}

GraphKruskal::~GraphKruskal()
{
	if (vertices != NULL)
		delete[] vertices;
}

bool GraphKruskal::InsertEdge(int fromVertex, int toVertex, double weight)
{
	if (fromVertex < 0 || fromVertex >= nVertex)
		return false;
	if (toVertex < 0 || toVertex >= nVertex)
		return false;

	Edge edge{ fromVertex, toVertex, weight };
	vertices[fromVertex].edges.push_back(edge);
	nEdge++;
	return true;
}

bool GraphKruskal::RemoveEdge(int fromVertex, int toVertex, double weight)
{
	if (fromVertex < 0 || fromVertex >= nVertex)
		return false;
	if (toVertex < 0 || toVertex >= nVertex)
		return false;
	if (vertices[fromVertex].edges.empty())
		return false;

	const list<Edge> &edge = vertices[fromVertex].edges;

	list<Edge>::const_iterator it;
	for (it = edge.begin(); it != edge.end();)
	{
		if (it->endVertex == toVertex || it->weight == weight)
		{ // �����ϴ� Vertex ��ġ�� ����, ���԰� ������
			vertices[fromVertex].edges.erase(it);
			nEdge--;
			return true;
		}
		else
			it++;
	}

	return false;
}

bool GraphKruskal::IsConnected(int aVertex, int bVertex)
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

		if (curVertex.id == vertices[bVertex].id)
			return true;

		//if (curVertex.visited)
		//	continue;

		curVertex.visited = true;
		HandleVertex(curVertex);

		const list<Edge> &edges = curVertex.edges;

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

bool GraphKruskal::BuildSpanningTree()
{
	PrintAllEdges();

	list<Edge> restoreEdges;
	priority_queue<Edge> priorityEdges;
	int vertexIndex = 0;

	for (int i = 0; i < nVertex; i++) // weight �켱������ ���
	{
		const list<Edge> &edges = vertices[i].edges;

		list<Edge>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			priorityEdges.push(*it);
		}
	}

	while (!priorityEdges.empty())
	{
		if ((nVertex - nEdge) > 1) // Vertex�� �ϳ��� ������ �Ǿ����� �ʴٸ�
			return false;

		// priorityEdges���� ����ġ�� ���� ���� Edge�� ������ ������
		Edge heavyEdge = priorityEdges.top();
		restoreEdges.push_back(heavyEdge);
		priorityEdges.pop();

		// priorityEdges���� ���� Edge�� ������ �׷������� �����Ѵ�
		RemoveEdge(heavyEdge.startVertex, heavyEdge.endVertex, heavyEdge.weight);

		// Edge�� �����ϰ� �� Vertex�� �����ϴ� ��ΰ� �ִ��� Ȯ���Ѵ�
		if (!IsConnected(heavyEdge.startVertex, heavyEdge.endVertex)) // �������� ���ߴٸ�
		{
			InsertEdge(restoreEdges.back().startVertex, restoreEdges.back().endVertex, restoreEdges.back().weight);
			restoreEdges.pop_back();
		}
	}
	PrintAllEdges();

	return true;
}

void GraphKruskal::PrintAllEdges()
{
	for (int i = 0; i < nVertex; i++)
	{
		const list<Edge> &edges = vertices[i].edges;

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


void GraphKruskal::HandleVertex(const Vertex &vertex)
{
	cout << "  . Visited vertex number : " << vertex.id << endl;
}

void GraphKruskal::ResetVisited()
{
	for (int i = 0; i < nVertex; i++)
		vertices[i].visited = false;
}
