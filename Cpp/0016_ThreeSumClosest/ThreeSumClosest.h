#pragma once
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static int TwoThread(vector<int>& nums, int target) {
		const int n = nums.size();
		sort(nums.begin(), nums.end());
		int ans = nums[0] + nums[1] + nums[2];
		if (n == 3)
			return ans;
		for (auto i = 0; i < n - 2; ++i) {
			int k = n - 1;
			const int a = nums[i];
			for (auto j = i + 1; j < n - 1; ++j) {
				const int b = nums[j];
				while (j < k && a + b + nums[k] > target) { k--; }
				int temp;
				if (k != n - 1) {
					temp = a + b + nums[k + 1];
					if (abs(ans - target) > temp - target)
						ans = temp;
				}
				if (j == k)
					break;
				temp = a + b + nums[k];
				if (temp == target) { return target; }
				if (abs(ans - target) > target - temp)
					ans = temp;
			}
		}
		return ans;
	}

	static int TwoThread2(vector<int>& nums, int target) {
		const int n = nums.size();
		sort(nums.begin(), nums.end());
		int ans = nums[0] + nums[1] + nums[2];
		if (n == 3)
			return ans;
		for (auto i = 0; i < n - 2; ++i) {
			int k = n - 1;
			int j = i + 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == target)
					return target;
				if (abs(target - ans) > abs(target - sum))
					ans = sum;
				if (sum > target)
					k--;
				else
					j++;
			}
		}
		return ans;
	}
};
