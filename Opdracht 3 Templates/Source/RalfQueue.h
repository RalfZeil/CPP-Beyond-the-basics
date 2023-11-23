#pragma once
#include <iostream>
#include <vector>

template<class T>
class RalfQueue
{
private:
	std::vector<T> queue;
public:
	RalfQueue();
	void Enqueue(T value);
	T Dequeue();
	int Size() const;
};

template<class T>
RalfQueue<T>::RalfQueue()
{	
}

template<class T>
void RalfQueue<T>::Enqueue(T value)
{
	queue.insert(queue.begin(), value);
	std::cout << "Added value: " << value << std::endl;
}

template<class T>
T RalfQueue<T>::Dequeue()
{
	T removedValue = queue.back();
	queue.pop_back();
	std::cout << "Removed value: " << removedValue << std::endl;
	return removedValue;
}

template<class T>
int RalfQueue<T>::Size() const
{
	return queue.size();
}

