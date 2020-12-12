#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

namespace three_sum {
	class Solution {
		static vector<int> TwoSumHashMap(vector<int>& nums, int target) {
			unordered_map<int, int> num_hash_map;
			vector<int> ans;
			for (auto i = 0; nums.size() > i; i++) {
				if (i == target)
					continue;
				auto iter = num_hash_map.find(nums[target] - nums[i]);
				if (iter != num_hash_map.end()) {
					ans.push_back(nums[i]);
					ans.push_back(iter->first);
					return ans;
				}
				num_hash_map.insert_or_assign(nums[i], i);
			}
			return ans;
		}

	public:
		static vector<vector<int>> Directly(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> ans;
			int n = nums.size();
			for (int i = 0; i < n - 2; ++i) {
				if (i > 0 && nums[i - 1] == nums[i])
					continue;
				for (int j = i + 1; j < n - 1; ++j) {
					if (j > i + 1 && nums[j - 1] == nums[j])
						continue;
					for (int k = j + 1; k < n; ++k) {
						if (k < n - 1 && nums[k] == nums[k + 1])
							continue;
						if (nums[i] + nums[j] + nums[k] == 0) {
							ans.push_back({nums[i], nums[j], nums[k]});
							break;
						}
					}
				}
			}
			return ans;
		}

		static vector<vector<int>> TwoThread(vector<int>& nums) {
			vector<vector<int>> ans;
			const int n = nums.size();
			if (n < 3)
				return ans;
			sort(nums.begin(), nums.end());
			int k = n - 1;
			int target = -nums[0];
			for (auto j = 1; j < n - 1; ++j) {
				if (j > 1 && nums[j] == nums[j - 1])
					continue;
				while (j < k && nums[j] + nums[k] > target) { k--; }
				if (j == k)
					break;
				if (nums[j] + nums[k] == target) { ans.push_back({-target, nums[j], nums[k]}); }
			}
			for (auto i = 1; i < n - 2; ++i) {
				if (nums[i - 1] == nums[i])
					continue;
				k = n - 1;
				target = -nums[i];
				for (auto j = i + 1; j < n - 1; ++j) {
					if (j > i + 1 && nums[j] == nums[j - 1])
						continue;
					while (j < k && nums[j] + nums[k] > target) { k--; }
					if (j == k)
						break;
					if (nums[j] + nums[k] == target) { ans.push_back({-target, nums[j], nums[k]}); }
				}
			}
			return ans;
		}

		static vector<vector<int>> hashMap(vector<int>& nums) {
			vector<vector<int>> ans;
			auto n = nums.size();
			if (n < 3)
				return ans;
			unordered_map<int, int> numHashMap;
			for (int i = 0; i < n; ++i) { numHashMap.insert_or_assign(nums[i], i); }
			for (int i = 0; i < n - 1; ++i) {
				for (int j = i + 1; j < n; ++j) {
					const auto iter = numHashMap.find(- nums[i] - nums[j]);
					if (iter != numHashMap.end()) {
						auto k = iter->second;
						if (k != i && k != j) {
							vector<int> temp = {nums[i], nums[j], iter->first};
							sort(temp.begin(), temp.end());
							if (ans.empty() || find(ans.begin(), ans.end(), temp) == ans.end()) { ans.push_back(temp); }
						}
					}
				}
			}
			return ans;
		}
	};
}
