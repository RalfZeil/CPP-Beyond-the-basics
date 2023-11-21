#include "NPC.h"
#include "iostream"

NPC::NPC(std::string _name) : name(_name)
{}

void NPC::Render()
{
	std::cout << name << std::endl;
}
