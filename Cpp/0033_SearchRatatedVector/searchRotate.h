#pragma once
#include <vector>
using namespace std;

namespace searchRotate {
	class Solution {

	public:
		static int recur(vector<int>& nums, int target) {
			int hi = nums.size();
			if (!hi)
				return -1;
			auto lo = 0;

			while (1 < hi - lo) {
				const auto mi = (hi + lo) >> 1;
				if (nums[lo] < nums[mi]) {
					if (nums[lo] <= target && target < nums[mi]) { hi = mi; }
					else { lo = mi; }
				}
				else {
					if (nums[mi] <= target && target <= nums[hi - 1]) { lo = mi; }
					else { hi = mi; }
				}
			}
			return nums[lo] == target ? lo : -1;
		}
	};
}
