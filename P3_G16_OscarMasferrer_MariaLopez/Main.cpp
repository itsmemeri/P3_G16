#include <fstream>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "Map.h"
#include"Entios.h"

Map mimapa;
	
void main()
{
	mimapa.ReadMap();
	mimapa.PrintMap();
}