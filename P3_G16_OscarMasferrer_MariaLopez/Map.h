#pragma once
#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"

class Map
{
public:
	static const int rows = 36;
	static const int columns = 74;

	char mapa[rows][columns];

	void ReadMap();
	void PrintMap();
	Map();
	~Map();

};

