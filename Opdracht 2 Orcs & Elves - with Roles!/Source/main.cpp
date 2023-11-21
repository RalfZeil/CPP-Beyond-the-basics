#include <iostream>
#include "Elf.h"
#include "Orc.h"
#include "FarmerDecorator.h"
#include "Shaman.h"
#include "Soldier.h"

int main()
{
    FarmerDecorator* elfFarmer = new FarmerDecorator(new Elf(new NPC("Gniesbert")));
    Shaman* orcShaman = new Shaman(new Orc(new NPC("Ork")));
    NPC* uberCreature = new Soldier(new Elf(new Orc(new NPC("Minoes"))));

    elfFarmer->Render();
    orcShaman->Render();
    uberCreature->Render();
}
