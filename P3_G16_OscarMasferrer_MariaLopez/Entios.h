#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "Map.h"

class Entios
{
public:
	int posX, posY, stamina;
	Map mimapa;
	void Entios::GetEntios(Map mimapa, char skin);
	void Entios::Move(Entios player);
	Entios();
	~Entios();
};

