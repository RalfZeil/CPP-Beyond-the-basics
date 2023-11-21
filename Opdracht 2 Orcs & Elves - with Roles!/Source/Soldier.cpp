#include "Soldier.h"
#include <iostream>
#include "NPC.h"

Soldier::Soldier(NPC* npc) : BaseDecorator(npc)
{}

void Soldier::Render()
{
	BaseDecorator::Render();
	std::cout << "Soldier" << std::endl;
}
