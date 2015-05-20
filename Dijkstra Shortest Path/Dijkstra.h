#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <limits>
#include <vector>
#include "Cell.h"

class Graph
{
public:
	Graph(int dimension)
	{
		this->dimension = dimension;
		initializeCell();
	}

	void dijkstraAlg(const int(&matrix)[6][6], int startPt);
	void printTable();

private:
	int dimension;
	std::vector<Cell> table;

	void initializeCell();
	bool checkExpanded();
	int getSmallestVal(const int (&matrix)[6][6], int row);
};

#endif