#include "GraphKruskal.h"

int main()
{

	GraphKruskal* graph = new GraphKruskal(5);
	graph->InsertEdge(0, 1, 4.);
	graph->InsertEdge(0, 2, 2.);
	graph->InsertEdge(0, 4, 3.);
	graph->InsertEdge(1, 4, 5.);
	graph->InsertEdge(1, 3, 1.);
	graph->InsertEdge(2, 4, 6.);
	graph->InsertEdge(3, 0, 8.);
	graph->InsertEdge(3, 4, 9.);
	graph->InsertEdge(4, 0, 7.);

	graph->BuildSpanningTree();

	return 0;
}