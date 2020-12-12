// Joe
// 周漫
// 2020080619:16


#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

namespace num_identical_pairs {
	class Solution {
	public:
		int CountBySort(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			int n = nums.size();
			if (n == 1) return 1;
			int ans = 0;
			int s = 1;
			for (int i = 1; i < n; ++i) {
				if(nums[i] == nums[i-1]) {				
					s++;
				}
				else {
					ans += s * (s - 1) / 2;
					s = 1;
				}
			}
			ans += s * (s - 1) / 2;
			return ans;
		}
		int CountByHashSet(vector<int>& nums) {
			unordered_map<int, int> nums_map;
			for (auto num : nums) {
				if (nums_map.count(num)) {
					nums_map[num] += 1;
				}
				else {
					nums_map[num] = 1;
				}
			}
			int ans = 0;
			for (auto pair : nums_map) {
				auto v = pair.second;
				if(1 < v) {
					ans += v * (v - 1) / 2;
				}
			}
			return ans;
		}
	};
}
