#include "Dijkstra.h"

void Graph::initializeCell()
{
	for (int i = 0; i < dimension; i++)
	{
		table[i] = Cell();
	}
}

bool Graph::checkExpanded()
{
	for (int i = 0; i < dimension; i++)
	{
		if (table[i].getisExpanded() != true)
			return true;
		else
			return false;
	}
}

int Graph::getSmallestVal(int(&matrix)[6][6], int row)
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

void Graph::dijkstraAlg(int(&matrix)[6][6], int startPt)
{
	int min = maxValue;
	int row = startPt;
	int column;
	initializeCell();
	table[row].setCost(0);
	table[row].setisExpanded();
	table[row].setParent(-1);

	while (checkExpanded())
	{
		for (int x = 0; x < dimension; x++)
		{
			if (matrix[row][x] != 0)
			{
				if ((matrix[row][x] + table[row].getCost()) < table[x].getCost())
				{
					table[x].setCost(matrix[row][x] + table[row].getCost());
				}
			}
		}
	}
}