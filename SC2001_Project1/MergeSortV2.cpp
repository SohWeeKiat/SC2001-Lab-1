#include "MergeSortV2.hpp"
#include <iostream>

void InsertionSort(std::vector<int>& nums, int left, int right);

namespace MergeSortV2 {
	int comparison = 0;

	void ResetComparison()
	{
		comparison = 0;
	}

	int GetComparison()
	{
		return comparison;
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

	void MergeSort(std::vector<int>& nums, int left, int right, int S)
	{	
		int length = right - left;
		if (length > S) {
			int mid = (left + right) / 2;
			MergeSort(nums, left, mid, S);
			MergeSort(nums, mid + 1, right, S);
			Merge(nums, left, mid, right);
		}
		else
			InsertionSort(nums, left, right);
	}

	void MergeSort(std::vector<int>& nums, int S)
	{
		ResetComparison();
		return MergeSort(nums, 0, nums.size() - 1, S);
	}
}

void InsertionSort(std::vector<int>& nums, int left, int right)
{
	if ((right - left) < 1) return;
	for (int i = left + 1; i <= right; i++) {
		for (int j = i; j > left; j--) {
			MergeSortV2::comparison++;
			if (nums[j] < nums[j - 1]) {
				//swap
				auto temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
			else
				break;
		}
	}
}