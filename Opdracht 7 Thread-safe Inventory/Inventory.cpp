#include "Inventory.h"

std::string Inventory::Get()
{
    std::lock_guard<std::mutex> lock(mtx);

    if (contents.size() < 1) 
    {
        return 0;
    }
    else 
    {
        std::string value = contents.back();
        contents.pop_back();
        return value;
    }
}

void Inventory::Put(std::string item)
{
    std::lock_guard<std::mutex> lock(mtx);
    contents.insert(contents.begin(), item);
}
