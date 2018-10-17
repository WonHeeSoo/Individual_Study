#pragma once
#include "LinkedList.h"

enum {A, B, C, D, E, F};

class Graph
{
public:
	Graph(int size);
	~Graph();

public:
	bool Insert(int fromPos, int toPos);
	bool DFS(int pos);
	bool BFS();
	
	void ShowGraph() const;

protected:
	//virtual bool AddEdge(int fromVertex, int toVertex) = 0;

private:
	void ResetSearch();

protected:
	int graphSize;
	int	vertexCnt;
	int edgeCnt;
	LinkedList *adjList;
};