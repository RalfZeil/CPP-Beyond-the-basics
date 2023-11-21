#include "Elf.h"
#include <iostream>

Elf::Elf(NPC* npc) : BaseDecorator(npc)
{}

void Elf::Render()
{
	BaseDecorator::Render();
	std::cout << "Elf" << std::endl;
}
