#include "Dijkstra.h"

int main()
{
	int infinity = std::numeric_limits<int>::max();
	static const int dimension = 6;
	int matrix[dimension][dimension] =
	{
		{ 0, 7, 9, infinity, infinity, 14 },
		{ 7, 0, 10, 15, infinity, infinity },
		{ 9, 10, 0, 11, infinity, infinity },
		{ infinity, 15, 11, 0, 6, infinity },
		{ infinity, infinity, infinity, 6, 0, 9 },
		{ 14, infinity, 2, infinity, 9, 0 }
	};


	Graph graph = Graph(dimension);
	//graph.printTable();
	graph.dijkstraAlg(matrix, 0);
	graph.printTable();

	//std::cout << infinity << std::endl;
}