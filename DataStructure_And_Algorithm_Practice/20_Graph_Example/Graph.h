#pragma once

#include <list>

/*struct Edge
{
	int		dest_id;
	bool	edge_visited;

	Edge(int dst = Vertex::INVALID_ID, bool visited = false)
		: dest_id(dst), edge_visited(visited) {}
};*/


struct Vertex
{
	int				id;
	bool			visited;
	std::list<int>	edges;

	static const int INVALID_ID;

	Vertex(int id = INVALID_ID, bool visited = false) : id(id), visited(visited) {}
};


class Graph
{
public:
	Graph(int numVertex);
	virtual ~Graph();

public:
	bool InsertEdge(int fromVertex, int toVertex);
	bool DFS(int startVertex);
	bool BFS(int startVertex);
	
	void ShowGraph() const;

protected:
	void HandleVertex(const Vertex &vertex);
	void ResetVisited();

protected:
	int			nVertex;
	Vertex		*vertices;
};