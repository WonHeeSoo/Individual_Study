#include "Graph.h"



int main()
{
	enum Pos { A, B, C, D, E };

	Graph* graph = new Graph(4);
	graph->Insert(0, 1);
	graph->Insert(1, 2);
	graph->Insert(1, 3);
	graph->Insert(4, 3);

	graph->DFS(0);

	return 0;
}