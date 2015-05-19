#include "Dijkstra.h"

void Graph::initializeCell()
{
	for (int i = 0; i < dimension; i++)
	{
		table.push_back(Cell());
	}
}

bool Graph::checkExpanded()
{
	bool isFalse = false;
	for (int i = 0; i < dimension; i++)
	{
		if (table[i].getisExpanded() != true)
		{
			isFalse = true;
		}
	}
	return isFalse;
}

int Graph::getSmallestVal(const int (&matrix)[6][6], int row)
{
	int column;
	int min = maxValue;
	for (int i = 0; i < dimension; i++)
	{
		if (matrix[row][i] < min)
		{
			min = matrix[row][i];
			column = i;
		}
	}
	return column;
}

void Graph::dijkstraAlg(const int (&matrix)[6][6], int startPt)
{
	int min = maxValue;
	int row = startPt;
	int column;
	initializeCell();
	table[row].setCost(0);
	table[row].setisExpanded();
	table[row].setParent(-1);
	std::cout << checkExpanded() << std::endl;
	while (checkExpanded())
	{
		//std::cout << checkExpanded() << std::endl;
		for (int x = 0; x < dimension; x++)
		{
			if (matrix[row][x] != 0)
			{
				if ((matrix[row][x] + table[row].getCost()) < table[x].getCost())
				{
					table[x].setCost(matrix[row][x] + table[row].getCost());
					table[x].setParent(row);
				}
			}
		}
		if (table[row].getisExpanded() == false)
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