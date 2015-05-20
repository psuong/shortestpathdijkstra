#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <vector>
#include "Cell.h"

class Graph
{
public:
	Graph(int dimension)
	{
		maxValue = 0x7FFFFFFF;
		this->dimension = dimension;
		initializeCell();
	}

	void dijkstraAlg(const int(&matrix)[6][6], int startPt); //performing Dijkstra's Shortest Path Algorithm
	void dijkstraAlg(int **&matrix, int startPt); //same as previous function, overloaded for pointers
	void printTable(); //prints the table of the shortest path from the starting point to every other vertex

private:
	int dimension; //dimension of the graph
	int maxValue; //the maximum value used for comparison
	std::vector<Cell> table; //Vector of Objects holding each value

	void initializeCell(); //initializes each cell of the table to default values
	bool checkExpanded(); //checks if each vertex has been expanded to

	int getSmallestVal(const int (&matrix)[6][6], int row); //gets the index of where the smallest value is (using a matrix built on the heap)

	int getSmallestVal(int **&matrix, int row); //overloaded function to take in pointers instead
};

#endif