#include "BaseDecorator.h"

BaseDecorator::BaseDecorator(NPC* _npc) : NPC(_npc->name), npc(_npc) {}

void BaseDecorator::Render()
{
	npc->Render();
}
