#pragma once
#include <vector>
using namespace std;

namespace sortColor {
	class Solution {
	public:
		static void sort(vector<int>& nums) {
			auto begin = 0;
			int end = nums.size() - 1;
			auto mid = 0;
			while (mid <= end) {
				if (nums[mid] == 2) { swap(nums[mid], nums[end--]); }
				else if (nums[mid] == 0) { swap(nums[mid++], nums[begin++]); }
				else { mid++; }
			}
		}
	};
}
