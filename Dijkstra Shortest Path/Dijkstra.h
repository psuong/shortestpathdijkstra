#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <limits>
#include "Cell.h"

class Graph
{
public:
	Graph(int dimension)
	{
		this->dimension = dimension;
		maxValue = std::numeric_limits<int>::max();
	}

	void dijkstraAlg(int(&matrix)[6][6], int startPt);
	void parentTable();
	void setEdges(int x, int y);

private:
	int maxValue;
	int dimension;
	int **graph = new int*[dimension];
	Cell *table = new Cell[dimension];

	void initializeCell();
	bool checkExpanded();
	int getSmallestVal(int(&matrix)[6][6], int row);
};

#endif