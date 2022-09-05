#include <iostream>
#include <chrono>
#include "MergeSortV1.hpp"
#include "MergeSortV2.hpp"

#define MIN_VALUE 1
#define MAX_VALUE 10000

std::vector<int> GenerateRandomNumbers(int size)
{
	std::vector<int> temp(size);
	for (int i = 0; i < size; i++)
		temp[i] = MIN_VALUE + rand() % MAX_VALUE;
	return temp;
}

int main()
{
	std::vector <std::vector<int>> original_data;
	for (int i = 1000; i <= 10000000; i *= 10) {
		std::cout << "----------Start----------" << std::endl;
		std::cout << "Generating random numbers, size = " << i << std::endl;
		auto numbers = GenerateRandomNumbers(i);
		original_data.push_back(numbers);

		auto start_time = std::chrono::high_resolution_clock::now();
		MergeSortV1::MergeSort(numbers);
		auto stop_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<
			std::chrono::microseconds>(stop_time - start_time);
		std::cout << "Time taken by MergeSort: "
			<< duration.count() << " microseconds" << std::endl;
		std::cout << "----------End----------" << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;

	for (int i = 1000, index = 0; i <= 10000000; i *= 10, index++) {
		std::cout << "----------Start----------" << std::endl;
		std::cout << "Generating random numbers, size = " << i << std::endl;
		auto numbers = original_data[index];

		auto start_time = std::chrono::high_resolution_clock::now();
		MergeSortV2::MergeSort(numbers, 5);
		auto stop_time = std::chrono::high_resolution_clock::now();


		auto duration = std::chrono::duration_cast<
			std::chrono::microseconds>(stop_time - start_time);
		std::cout << "Time taken by MergeSortV2: "
			<< duration.count() << " microseconds" << std::endl;
		std::cout << "----------End----------" << std::endl;
	}
}