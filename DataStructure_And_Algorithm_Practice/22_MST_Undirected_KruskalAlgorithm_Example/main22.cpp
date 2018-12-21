#include "UndirectedGraphKruskal.h"
#include <iostream>

int main()
{

	UndirectedGraphKruskal* graph = new UndirectedGraphKruskal(5);
	graph->InsertEdge(0, 1, 4.);
	graph->InsertEdge(0, 2, 3.);
	graph->InsertEdge(0, 4, 3.);
	graph->InsertEdge(1, 4, 5.);
	graph->InsertEdge(1, 3, 1.);
	graph->InsertEdge(2, 4, 6.);
	graph->InsertEdge(3, 0, 1.);
	graph->InsertEdge(3, 4, 9.);
	graph->InsertEdge(4, 0, 6.);

	if (graph->BuildSpanningTree())
		cout << "Success MST" << endl;
	else
		cout << "Fail" << endl;

	return 0;
}