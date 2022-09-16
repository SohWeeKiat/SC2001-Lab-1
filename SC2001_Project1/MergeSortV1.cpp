#include "MergeSortV1.hpp"
#include <iostream>

namespace MergeSortV1 {
	__int64 comparison = 0;
	__int64 iterations = 0;

	void ResetComparison()
	{
		comparison = 0;
	}

	__int64 GetComparison()
	{
		return comparison;
	}

	__int64 GetIterations()
	{
		return iterations;
	}

	void Merge(std::vector<int>& nums, int left_index, int mid, int right_index)
	{
		if (right_index - left_index <= 0) return;
		std::vector<int> left(nums.begin() + left_index, nums.begin() + mid + 1);
		std::vector<int> right(nums.begin() + mid + 1, nums.begin() + right_index + 1);

#if _DEBUG
		std::cout << "Merge: " << left_index << " " << mid << " " << right_index << std::endl;
		std::cout << "Left: ";
		for (int i = 0; i < left.size(); i++) 
			std::cout << left[i] << " ";
		std::cout << std::endl;
		std::cout << "Right: ";
		for (int i = 0; i < right.size(); i++)
			std::cout << right[i] << " ";
		std::cout << std::endl;
#endif

		int compare = 0;
		auto left_iter = left.begin();
		auto right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end()) {
			compare = *right_iter - *left_iter;
			comparison++;
			if (compare > 0) {//right is bigger
				nums[left_index++] = *left_iter;
				left_iter++;
			}
			else if (compare < 0) {//left is bigger
				nums[left_index++] = *right_iter;
				right_iter++;
			}
			else {//same
				nums[left_index++] = *left_iter;
				left_iter++;
				nums[left_index++] = *right_iter;
				right_iter++;
			}
		}
		for (; left_iter != left.end(); left_iter++)
			nums[left_index++] = *left_iter;
		for (; right_iter != right.end(); right_iter++)
			nums[left_index++] = *right_iter;
	}

	void MergeSort(std::vector<int>& nums, int left, int right)
	{
		int mid = (left + right) / 2;
		int length = right - left;
		if (length <= 5) {
			iterations++;
		}
		if (length <= 0) return;
		else if (length) {
			MergeSort(nums, left, mid);
			MergeSort(nums, mid + 1, right);
		}
#if _DEBUG
		std::cout << "Before: ";
		for (int i = 0; i < nums.size(); i++)
			std::cout << nums[i] << " ";
		std::cout << std::endl;
#endif

		Merge(nums, left, mid, right);

#if _DEBUG
		std::cout << "After: ";
		for (int i = 0; i < nums.size(); i++)
			std::cout << nums[i] << " ";
		std::cout << std::endl;
#endif
	}

	void MergeSort(std::vector<int>& nums)
	{
		ResetComparison();
		iterations = 0;
		MergeSort(nums, 0, nums.size() - 1);
		std::cout << "iterations: " << iterations << std::endl;
	}
}