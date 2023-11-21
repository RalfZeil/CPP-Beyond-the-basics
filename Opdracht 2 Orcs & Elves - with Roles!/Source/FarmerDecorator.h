#pragma once
#include "BaseDecorator.h"
#include "NPC.h"

class FarmerDecorator : public BaseDecorator
{
public:
	FarmerDecorator(NPC* npc);
	void Render() override;
};

