#include <iostream>
#include <chrono>
#include "MergeSortV1.hpp"
#include "MergeSortV2.hpp"
#include <Windows.h>
#include "CSVGenerator.hpp"

#define MIN_VALUE 1
#define MAX_VALUE INT_MAX

std::vector<int> GenerateRandomNumbers(unsigned int size)
{
	std::vector<int> temp(size);
	for (unsigned int i = 0; i < size; i++)
		temp[i] = MIN_VALUE + rand() % MAX_VALUE;
	return temp;
}

void TestOriginalMergeSort(std::vector<std::vector<int>>& original_data)
{
	CSVGenerator t("MergeSort.csv", "Size,Time,Comparison");
	for (int i = 0; i < original_data.size(); i++) {
		std::cout << "----------Start----------" << std::endl;
		auto numbers = original_data[i];
		std::cout << "size = " << numbers.size() << std::endl;

		auto start_time = std::chrono::high_resolution_clock::now();
		MergeSortV1::MergeSort(numbers);
		auto stop_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<
			std::chrono::microseconds>(stop_time - start_time);
		std::cout << "Time taken by MergeSort: "
			<< duration.count() << " microseconds" << std::endl;
		std::cout << "Number of comparisons: " << MergeSortV1::GetComparison() << std::endl;
		std::cout << "----------End----------" << std::endl;

		t.get() << numbers.size() << "," << duration.count() << "," << MergeSortV1::GetComparison() << "\n";
	}
}

void TestMergeInsertionSort(std::vector<std::vector<int>>& original_data, CSVGenerator& csv, int S)
{
	for (int index = 0; index < original_data.size(); index++) {
		std::cout << "----------Start----------" << std::endl;
		auto numbers = original_data[index];
		std::cout << "size = " << numbers.size() << std::endl;

		auto start_time = std::chrono::high_resolution_clock::now();
		MergeSortV2::MergeSort(numbers, S);
		auto stop_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<
			std::chrono::microseconds>(stop_time - start_time);
		std::cout << "Time taken by MergeSortV2: "
			<< duration.count() << " microseconds" << std::endl;
		std::cout << "Number of comparisons: " << MergeSortV2::GetComparison() << std::endl;
		std::cout << "----------End----------" << std::endl;

		csv.get() << numbers.size() << "," << S << "," << duration.count() << "," << MergeSortV2::GetComparison() << "\n";
	}
}

int main()
{
	srand(GetTickCount());
	std::vector<int> random_data = GenerateRandomNumbers(10000000);
	std::vector <std::vector<int>> original_data;
	for (int i = 1; i < 7; i++) {
		original_data.push_back(std::move(std::vector<int>(random_data.begin(), random_data.begin() + std::pow(10,i))));
	}
	for (unsigned int i = 2000000; i < 10000000; i += 500000)
		original_data.push_back(std::move(std::vector<int>(random_data.begin(), random_data.begin() + i)));
	original_data.push_back(random_data);

	TestOriginalMergeSort(original_data);
	std::cout << "-----------------------------------------------" << std::endl;
	CSVGenerator t("MergeInsertion.csv", "Size,S,Time,Comparison");
	for (int i = 0; i < 500; i++) {
		TestMergeInsertionSort(original_data, t, i);
	}

	
}