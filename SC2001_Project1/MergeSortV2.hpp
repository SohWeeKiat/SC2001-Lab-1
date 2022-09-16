#pragma once
#include <vector>

namespace MergeSortV2 {
	void MergeSort(std::vector<int>& nums, int S);
	void ResetComparison();
	__int64 GetComparison();
	__int64 GetIterations();
}