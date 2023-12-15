#pragma once
#include <vector>
#include <string>
#include <thread>
#include <mutex>

class Inventory
{
public:
	std::vector<std::string> contents;
	std::mutex mtx;

	std::string Get();
	void Put(std::string item);
};

