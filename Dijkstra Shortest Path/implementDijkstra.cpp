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
	/*int column;
	for (int i = 0; i < dimension; i++)
	{
		if (matrix[row][i] < min)
		{
			min = matrix[row][i];
			column = i;
		}
	}
	return column;*/
	return 0;
}

void Graph::dijkstraAlg(const int (&matrix)[6][6], int startPt)
{
	int row = startPt;
	int sum;
	int column;
	table[row].setCost(0);
	table[row].setParent(-1);
	while (checkExpanded())
	{
		for (int i = 0; i < dimension; i++)
		{
			sum = matrix[row][i] + table[row].getCost();
			if (matrix[row][i] != 0 && sum < table[i].getCost() && table[i].getisExpanded() != true)
			{
				table[i].setCost(sum);
				std::cout << sum << std::endl;
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