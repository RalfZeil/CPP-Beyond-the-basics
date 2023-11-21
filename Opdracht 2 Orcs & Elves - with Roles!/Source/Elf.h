#pragma once
#include <string>
#include "BaseDecorator.h"

class Elf : public BaseDecorator
{
public:
	Elf(NPC* npc);
	void Render() override;
};

