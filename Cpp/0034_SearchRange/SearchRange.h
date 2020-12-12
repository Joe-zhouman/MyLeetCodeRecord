#pragma once
#include <vector>
#include <algorithm>
using namespace std;

namespace searchRange {
	class Solution {
		static int lowerBound(vector<int>& nums, int target) {
			const auto lower = target - 0.5;
			int hi = nums.size();
			auto lo = 0;
			if (lower < nums[lo])
				return 0;
			if (nums[hi - 1] < lower)
				return hi;
			while (1 < hi - lo) {
				auto mi = (hi + lo) >> 1;
				if (nums[mi] < lower)
					lo = mi;
				else
					hi = mi;
			}
			return hi;
		}

		static int upperBound(vector<int>& nums, int target) {
			const auto upper = target + 0.5;
			int hi = nums.size();
			auto lo = 0;
			if (nums[hi - 1] < upper)
				return hi - 1;
			if (upper < nums[lo])
				return -1;
			while (1 < hi - lo) {
				auto mi = (hi + lo) >> 1;
				if (nums[mi] < upper)
					lo = mi;
				else
					hi = mi;
			}
			return lo;

		}

	public:
		static vector<int> binSearchBound(vector<int>& nums, int target) {
			if (nums.empty())
				return {-1, -1};
			const auto lower = lowerBound(nums, target);
			const auto upper = upperBound(nums, target);
			if (lower == nums.size() || upper == -1)
				return {-1, -1};
			if (nums[lower] == nums[upper])
				return {lower, upper};
			return {-1, -1};
		}
	};
}
