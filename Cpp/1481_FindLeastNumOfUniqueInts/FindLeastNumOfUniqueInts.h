// Administrator
// LeetCode-Cpp
// 1481_FindLeastNumOfUniqueInts
// 2020-07-26-22:26
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <vector>
#include <unordered_map>
class bin_idx_tree {
	std::vector<int> data_;
	unsigned int size_;

public:
	bin_idx_tree(unsigned int n) : data_(n + 1),
	                             size_(n + 1) { }

	static unsigned int lowbit(unsigned int x) { return x & (-x); }

	int get(unsigned int p) {
		int r = 0;
		for (; p; p -= lowbit(p))
			r += data_[p];
		return r;
	}

	void add(unsigned int p, int v) {
		for (; p < size_; p += lowbit(p))
			data_[p] += v;
	}
};
class Solution {
public:
	int find_least_num_of_unique_ints(std::vector<int>& arr, int k) {
		std::unordered_map<int, int> nums;
	}
};
