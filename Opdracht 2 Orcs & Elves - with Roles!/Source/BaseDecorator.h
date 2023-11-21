#pragma once
#include "NPC.h"

class BaseDecorator : public NPC
{
protected:
	
public:
	NPC* npc;
	BaseDecorator(NPC* _npc);
	void Render() override;
};

