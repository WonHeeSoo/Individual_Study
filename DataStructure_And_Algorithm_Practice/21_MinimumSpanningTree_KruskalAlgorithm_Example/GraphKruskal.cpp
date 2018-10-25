#include "GraphKruskal.h"
#include <iostream>
#include <stack>

const int Vertex::INVALID_ID = -1;

GraphKruskal::GraphKruskal(int numVertex) : nVertex(numVertex)
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

	list<Edge>::const_iterator it;
	for (it = edge.begin(); it != edge.end();)
	{
		if (it->endVertex == toVertex || it->weight == weight)
		{ // �����ϴ� Vertex ��ġ�� ����, ���԰� ������
			vertices[fromVertex].edges.erase(it);
			//priorityEdges.pop(); kruskalMST()���� �۾�
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
		}
	}

	ResetVisited();
	return false;
}

bool GraphKruskal::KruskalMST()
{
	list<Edge> restoreEdge;
	int vertexIndex = 0;

	while (nEdge + 1 != nVertex) // Edge + 1 == Vertex�� �����Ҷ�����
	{
		if (nEdge - nVertex < -1) // Vertex�� �ϳ��� ������ �Ǿ����� �ʴٸ�
			return false;

		// �켱���� ť���� ����ġ�� ���� ���� ������ ������ ������
		Edge heavyEdge = priorityEdges.top();
		restoreEdge.push_back(heavyEdge);
		priorityEdges.pop();

		// �켱���� ť���� ���� ������ ������ �׷������� �����Ѵ�
		RemoveEdge(heavyEdge.startVertex, heavyEdge.endVertex, heavyEdge.weight);
		/*
		const list<Edge> &edges = vertices[heavyEdge.startVertex].edges;

		list<Edge>::const_iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			if (it->endVertex == heavyEdge.endVertex && it->weight == heavyEdge.weight)
			{ // �����ϴ� Vertex�� ���� ���԰� ������
				RemoveEdge(it->startVertex, it->endVertex, it->weight);
				break;
			}
		}*/


		// ������ �����ϰ� �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ���Ѵ�
		if (!ConnectVertices(heavyEdge.startVertex, heavyEdge.endVertex)) // �������� ���ߴٸ�
		{
			InsertEdge(restoreEdge.back().startVertex, restoreEdge.back().endVertex, restoreEdge.back().weight);
			restoreEdge.pop_back();
		}
	}
	PrintAllEdges();
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
