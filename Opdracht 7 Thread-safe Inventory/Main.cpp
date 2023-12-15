#include <iostream>
#include <string>
#include "Inventory.h"

Inventory* inv;

template<typename T>
void PrintListResults(std::string label, std::vector<T> const& vec)
{
    std::cout << std::endl << label << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

void AddItems() 
{
    inv->Put("Sword");
    inv->Put("Shield");
    inv->Put("Spear");
    inv->Put("Mace");
    inv->Put("Bow");
    inv->Put("Halbert");
    inv->Put("Hammer");
}

void AddOtherItems()
{
    inv->Put("Ice Sword");
    inv->Put("Rock Shield");
    inv->Put("Thunder Spear");
    inv->Put("Dark Mace");
    inv->Put("Light Bow");
    inv->Put("Lava Halbert");
    inv->Put("BIG Hammer");
}

int main()
{
    inv = new Inventory();

    std::thread adderThread(AddItems);
    std::thread getterThread(AddOtherItems);

    adderThread.join();
    getterThread.join();

    PrintListResults<std::string>("Inventory contents: ", inv->contents);

    return 0;
}