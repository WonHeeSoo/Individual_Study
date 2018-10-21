#include "Graph.h"



int main()
{
	
	Graph* graph = new Graph(5);
	graph->InsertEdge(0, 1);
	graph->InsertEdge(0, 2);
	graph->InsertEdge(0, 4);
	graph->InsertEdge(1, 4);
	graph->InsertEdge(1, 3);
	graph->InsertEdge(2, 4);
	graph->InsertEdge(3, 0);
	graph->InsertEdge(4, 0);
	//graph->Insert(4, 3);

	graph->BFS(4);

	return 0;
}