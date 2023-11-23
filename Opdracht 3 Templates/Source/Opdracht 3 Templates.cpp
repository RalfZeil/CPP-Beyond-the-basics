#include <iostream>
#include "RalfQueue.h"

template <typename T, std::size_t N>
constexpr std::size_t GetArrayLength(T(&)[N]) {
	return N;
}

template <typename T>
void SortArray(T* array, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i] == array[j]) { continue; }
			if (array[i] < array[j])
			{
				T temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

template<typename T>
void PrintArrayInConsole(T* array, size_t size) 
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	// Part 1 van de opdracht, functies hierboven zijn voor dit deel.
	int arr1[] = { 5, 1, 3 };
	double arr2[] = { 10.5, 1.2, 22032.4, -1.3 };
	std::string arr3[] = { "Wo", "rld!", "Hello ", };

	SortArray<int>(arr1, GetArrayLength(arr1));
	SortArray<double>(arr2, GetArrayLength(arr2));
	SortArray<std::string>(arr3, GetArrayLength(arr3));

	PrintArrayInConsole(arr1, GetArrayLength(arr1));
	PrintArrayInConsole(arr2, GetArrayLength(arr2));
	PrintArrayInConsole(arr3, GetArrayLength(arr3));

	// Part 2 van de opdracht, Queue class.
	RalfQueue<int>* queue = new RalfQueue<int>();
	queue->Enqueue(5);
	queue->Enqueue(10);
	queue->Enqueue(15);

	queue->Dequeue();
	queue->Dequeue();

	return 0;
}