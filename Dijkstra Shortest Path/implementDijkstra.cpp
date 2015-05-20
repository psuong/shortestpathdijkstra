#include "Dijkstra.h"

void Graph::initializeCell()
{
	for (int i = 0; i < dimension; i++)
	{
		Cell cell = Cell();
		cell.setVertex(i);
		cell.setCost(0x7FFFFFFF);
		table.push_back(cell);
	}
}

bool Graph::checkExpanded()
{
	bool isFalse = false;
	for (int i = 0; i < dimension; i++)
	{
		if (table[i].getisExpanded() == false)
		{
			isFalse = true;
			break;
		}
	}
	return isFalse;
}

int Graph::getSmallestVal(const int (&matrix)[6][6], int row)
{
	int min = maxValue;
	int column = NULL;
	for (int i = 0; i < dimension; i++)
	{
		if (matrix[row][i] < min && table[i].getisExpanded() == false)
		{
			min = matrix[row][i];
			column = i;
		}
	}
	return column;
}

int Graph::getSmallestVal(int **&matrix, int row)
{
	int min = maxValue;
	int column = NULL;
	for (int i = 0; i < dimension; i++)
	{
		if (matrix[row][i] < min && table[i].getisExpanded() == false)
		{
			min = matrix[row][i];
			column = i;
		}
	}
	return column;
}

void Graph::dijkstraAlg(const int (&matrix)[6][6], int startPt)
{
	int row = startPt;
	int sum;
	table[row].setCost(0);
	table[row].setParent(-1);
	while (checkExpanded()) //will always be true if the table has a "false"
	{
		for (int i = 0; i < dimension; i++)
		{
			sum = matrix[row][i] + table[row].getCost();
			//only takes into account if the index of the matrix is not 0 or Infinity and if the vertex is not expanded
			if (matrix[row][i] != 0 && sum < table[i].getCost() && matrix[row][i] != maxValue && table[i].getisExpanded() != true)
			{
				table[i].setCost(sum);
			}
		}
		table[row].setisExpanded();
		row = getSmallestVal(matrix, row);
	}
}

void Graph::dijkstraAlg(int **&matrix, int startPt)
{
	int row = startPt;
	int sum;
	table[row].setCost(0);
	table[row].setParent(-1);
	while (checkExpanded()) //will always be true if the table has a "false"
	{
		for (int i = 0; i < dimension; i++)
		{
			sum = matrix[row][i] + table[row].getCost();
			//only takes into account if the index of the matrix is not 0 or Infinity and if the vertex is not expanded
			if (matrix[row][i] != 0 && sum < table[i].getCost() && matrix[row][i] != maxValue && table[i].getisExpanded() != true)
			{
				table[i].setCost(sum);
			}
		}
		table[row].setisExpanded();
		row = getSmallestVal(matrix, row);
	}
}

void Graph::printTable()
{
	for (int i = 0; i < dimension; i++)
	{
		std::cout << "Vertex: " << i << " Expanded: " << table[i].getisExpanded() << " Cost: " << table[i].getCost() << std::endl;
	}
}