#include "Entios.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "Input.inl.hh"
#include "Map.h"


void Entios::GetEntios(Map mimapa, char skin)
{
	
	for (int i = 0; i < mimapa.rows; i++)
	{
		for (int j = 0; j < mimapa.columns - 1; j++)
		{
			if (mimapa.mapa[i][j] == skin)
			{
				posX = i;
				posY = j;
			}
		}	
	}
}

void Entios::Move(Entios player)
{
	
	char key = static_cast<char>(enti::getInputKey());

	if (key == 'w' || key == 'W' && posY > 0)
	{
		posY--;
		stamina++;
	}
	else if (key == 'a' || key == 'A' && posX > 0)
	{
		posX--;
		stamina++;
	}
	else if (key == 's' || key == 'S' && posY < mimapa.rows - 1)
	{
		posY++;
		stamina++;
	}
	else if (key == 'd' || key == 'D' && mimapa.columns - 1)
	{
		posX++;
		stamina++;
	}
}

Entios::Entios()
{
	stamina = 0;
}


Entios::~Entios()
{
}
