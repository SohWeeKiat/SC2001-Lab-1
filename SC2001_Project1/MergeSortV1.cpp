#include "MergeSortV1.hpp"

namespace MergeSortV1 {
	void Merge(std::vector<int>& nums, int left_index, int mid, int right_index)
	{
		if (right_index - left_index <= 0) return;
		std::vector<int> left(nums.begin() + left_index, nums.begin() + mid);
		std::vector<int> right(nums.begin() + mid + 1, nums.begin() + right_index);
		int compare = 0;
		auto left_iter = left.begin();
		auto right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end()) {
			compare = *right_iter - *left_iter;
			if (compare) {//right is bigger
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
		if (length <= 0) return;
		else if (length) {
			MergeSort(nums, left, mid);
			MergeSort(nums, mid + 1, right);
		}
		Merge(nums, left, mid, right);
	}

	void MergeSort(std::vector<int>& nums)
	{
		return MergeSort(nums, 0, nums.size());
	}
}