#include "Orc.h"
#include <iostream>

Orc::Orc(NPC* npc) : BaseDecorator(npc)
{}

void Orc::Render()
{
	BaseDecorator::Render();
	std::cout << "Orc" << std::endl;
}
