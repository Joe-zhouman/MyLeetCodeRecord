#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static void Directly(vector<int>& nums) {
		int n = nums.size();
		int i = n - 2;
		for (; i >= 0; --i) {
			if (nums[i + 1] > nums[i])
				break;
		}
		if (i < 0) {
			reverse(nums.begin(), nums.end());
			return;
		}
		int temp = i + 1;
		int a = nums[temp];
		for (int k = temp; k < n; k++) {
			if (nums[k] > nums[i] && nums[k] <= a) {
				a = nums[k];
				temp = k;
			}
		}
		swap(nums[i], nums[temp]);
		reverse(nums.begin() + i + 1, nums.end());
	}

	static void Stl(vector<int>& nums) {
		auto i = is_sorted_until(nums.rbegin(), nums.rend());
		if (i != nums.rend())
			iter_swap(i, upper_bound(nums.rbegin(), i, *i));
		reverse(nums.rbegin(), i);
	}

	static void StlFun(vector<int>& nums) { next_permutation(nums.begin(), nums.end()); }

};
