#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "Map.h"
#include <stack>

class Entios
{
public:
	char skin;
	int posX, posY, stamina;

	struct entioPos;

	std::stack<entioPos> undoPos;
	std::stack<entioPos> redoPos;
	
	Map mimapa;
	
	void Entios::GetEntios(Map mimapa, char skin);
	void Entios::Move(Entios player);
	
	void Entios::undoMove(Entios player);
	void Entios::redoMove(Entios player);
	
	Entios();
	~Entios();
};

