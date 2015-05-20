#include "Dijkstra.h"

void testDijkstra()
{
	int dimension = 4;
	int maxValue = 0x7FFFFFFF;

	Graph newGraph = Graph(dimension);
	int **matrix = new int*[dimension];
	
	for (int i = 0; i < dimension; i++)
		matrix[i] = new int[dimension];

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = maxValue;
		}
	}

	matrix[0][1] = 5;
	matrix[0][3] = 2;
	matrix[1][0] = 5;
	matrix[2][3] = 1;
	matrix[3][0] = 2;
	matrix[3][2] = 1;

	newGraph.dijkstraAlg(matrix, 0);
	newGraph.printTable();
}

int main()
{
	//below is simply my test case to see if Dijkstra's Algorithm works
	/*
	int infinity = 0x7FFFFFFF;
	static const int dimension = 6;
	int matrix[dimension][dimension] =
	{
		{ 0, 7, 9, infinity, infinity, 14 },
		{ 7, 0, 10, 15, infinity, infinity },
		{ 9, 10, 0, 11, infinity, 2 },
		{ infinity, 15, 11, 0, 6, infinity },
		{ infinity, infinity, infinity, 6, 0, 9 },
		{ 14, infinity, 2, infinity, 9, 0 }
	};


	Graph graph = Graph(dimension);
	graph.dijkstraAlg(matrix, 0);
	graph.printTable();
	*/

	testDijkstra();
}