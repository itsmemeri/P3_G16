#include "Entios.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "Input.inl.hh"
#include "Map.h"
#include <stack>

struct entioPos {
	int prevPosX;
	int prevPosY;
	char skin;
};

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
		player.posY--;
		player.stamina++;
		player.undoPos.emplace(posX, posY, player.skin);
	}
	else if (key == 'a' || key == 'A' && posX > 0)
	{
		player.posX--;
		player.stamina++;
		player.undoPos.emplace(posX, posY, player.skin);
	}
	else if (key == 's' || key == 'S' && posY < mimapa.rows - 1)
	{
		player.posY++;
		player.stamina++;
		player.undoPos.emplace(posX, posY, player.skin);
	}
	else if (key == 'd' || key == 'D' && mimapa.columns - 1)
	{
		player.posX++;
		player.stamina++;
		player.undoPos.emplace(posX, posY, player.skin);
	}
}

void Entios::undoMove(Entios player)
{
	if (static_cast<char>(enti::getInputKey()) == 'z' || static_cast<char>(enti::getInputKey()) == 'Z')
	{
		player.redoPos.emplace(player.posX, player.posY, player.skin);
		player.posX = undoPos.top.prevPosX;
		player.posY = undoPos.top.prevPosY;
		player.stamina++;
		undoPos.pop();
	}
}

void Entios::redoMove(Entios player)
{
	if (static_cast<char>(enti::getInputKey()) == 'x' || static_cast<char>(enti::getInputKey()) == 'X')
	{
		player.undoPos.emplace(player.posX, player.posY, player.skin);
		player.posX = redoPos.top.prevPosX;
		player.posY = redoPos.top.prevPosY;
		player.stamina--;
		redoPos.pop();
	}
}

Entios::Entios()
{
	stamina = 0;
}


Entios::~Entios()
{
}
