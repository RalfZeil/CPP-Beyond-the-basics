#pragma once
#include <string>
#include "BaseDecorator.h"

class Orc : public BaseDecorator
{
public:
	Orc(NPC* npc);
	void Render() override;
};

