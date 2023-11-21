#include "FarmerDecorator.h"
#include <iostream>
#include "NPC.h"

FarmerDecorator::FarmerDecorator(NPC* npc) : BaseDecorator(npc)
{}

void FarmerDecorator::Render()
{
	BaseDecorator::Render();
	std::cout << "Farmer" << std::endl;
}
