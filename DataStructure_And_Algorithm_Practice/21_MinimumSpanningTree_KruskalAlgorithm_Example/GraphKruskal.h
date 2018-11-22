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
	list<Edge>		edges;

	static const int INVALID_ID;

	Vertex(int id = INVALID_ID, bool visited = false) : id(id), visited(visited) {}

	//bool operator==(const Vertex &r_vertex) const;
};

// GraphKruskal : Weighted, undirected acyclic graph with spanning tree
class GraphKruskal
{
public:
	GraphKruskal(int numVertex);
	virtual ~GraphKruskal();

public:
	bool InsertEdge(int fromVertex, int toVertex, double weight);
	bool RemoveEdge(int fromVertex, int toVertex, double weight);
	bool IsConnected(int aVertex, int bVertex);
	bool BuildSpanningTree();
	void PrintAllEdges();

protected:
	static void HandleVertex(const Vertex &vertex);
	
	void ResetVisited();

protected:
	int						nVertex;
	int						nEdge;
	Vertex					*vertices;
};
