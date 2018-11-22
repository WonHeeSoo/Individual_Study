#pragma once
#include <queue>
#include <list>

using namespace std;

struct Edge
{
	int		startVertex;
	int		endVertex;
	double	weight;

	static const int	INVALID_ID;

	Edge(int startVertex = INVALID_ID, int endVertex = INVALID_ID, double weight = 0.)
		: startVertex(startVertex), endVertex(endVertex), weight(weight) {}

	bool operator<(const Edge &r_val) const;
};


struct Vertex
{
	int				id;
	bool			visited;

	static const int INVALID_ID;

	Vertex(int id = INVALID_ID, bool visited = false) : id(id), visited(visited) {}

};

// UndirectedGraphKruskal : Weighted, undirected acyclic graph with spanning tree
class UndirectedGraphKruskal
{
public:
	UndirectedGraphKruskal(int numVertex);
	virtual ~UndirectedGraphKruskal();

public:
	bool InsertEdge(int aNode, int bNode, double weight);
	bool RemoveEdge(int aNode, int bNode, double weight);
	bool IsConnected(int aNode, int bNode);
	bool BuildSpanningTree();
	void PrintAllEdges();

protected:
	static void HandleVertex(const Vertex &vertex);

	void ResetVisited();

protected:
	int			nVertex;
	int			nEdge;
	Vertex		*vertices;
	list<Edge>	*allEdges;
};
