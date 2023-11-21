#pragma once
#include <string>

class NPC
{
public:
	std::string name;
	NPC(std::string _name);
	virtual void Render();
};

