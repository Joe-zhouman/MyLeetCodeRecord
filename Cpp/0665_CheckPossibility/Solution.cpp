#include "Solution.h"

bool solution::CheckPossibility(vector<int>& nums) {
	if (nums.size() < 3)
		return true;
	int unsorted = nums[0] > nums[1] ? 1 : 0;
	for (int i = 1; i < nums.size() - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			unsorted++;
			if (i < nums.size() - 2 &&
			    nums[i - 1] > nums[i + 1] && nums[i] > nums[i + 2])
				return false;
			if (unsorted > 1)
				return false;
		}
	}
	return true;
}
