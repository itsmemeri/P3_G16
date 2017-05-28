#pragma once
#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"

class Map
{
public:
	const int rows;
	const int columns;

	char mapa[rows][columns];

	void ReadMap();
	void PrintMap();
	Map();
	~Map();

};

