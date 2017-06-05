#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"



void Map::ReadMap()
{
	std::ifstream fentrada("default.cfg", std::ios::out);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns - 1; j++)
		{
			fentrada >> mapa[i][j];
			enti::cout << mapa[i][j];
		}
		enti::cout << enti::endl;
	}
	enti::cout << enti::cend;
	fentrada.close();

}
void Map::PrintMap()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns - 1; j++)
		{
			if (mapa[i][j] == 'X')
			{
				enti::cout <</*enti::Color::RED*/ mapa[i][j];
			}
			else if (mapa[i][j] == 'O')
			{
				enti::cout << /*enti::Color::CYAN*/ mapa[i][j];
			}
			else if (mapa[i][j] == ':')
			{
				enti::cout << /*enti::Color::GREEN*/ mapa[i][j];
			}
			else if (mapa[i][j] == '.')
			{
				enti::cout << /*enti::Color::WHITE*/ mapa[i][j];
			}
			else
			{
				enti::cout << /*enti::Color::YELLOW*/ mapa[i][j];
			}
		}
		enti::cout << enti::endl;
	}
	enti::cout << enti::cend;
	
}

Map::Map()
{
	Map::ReadMap();
}


Map::~Map()
{
}
