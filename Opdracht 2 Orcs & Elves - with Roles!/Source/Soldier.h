#pragma once
#include "BaseDecorator.h"
#include "NPC.h"

class Soldier : public BaseDecorator
{
public:
	Soldier(NPC* npc);
	void Render() override;
};

