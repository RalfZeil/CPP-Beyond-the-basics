#include "Shaman.h"
#include <iostream>
#include "NPC.h"

Shaman::Shaman(NPC* npc) : BaseDecorator(npc)
{}

void Shaman::Render()
{
	BaseDecorator::Render();
	std::cout << "Shaman" << std::endl;
}

