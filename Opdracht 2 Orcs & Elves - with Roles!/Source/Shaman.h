#pragma once
#include "BaseDecorator.h"
#include "NPC.h"

class Shaman : public BaseDecorator
{
public:
	Shaman(NPC* npc);
	void Render() override;
};

