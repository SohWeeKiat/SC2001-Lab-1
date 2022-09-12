#pragma once
#include <vector>

namespace MergeSortV1 {
	void MergeSort(std::vector<int>& nums);
	void ResetComparison();
	__int64 GetComparison();
	__int64 GetIterations();
}