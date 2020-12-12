// Joe
// LeetCode-Cpp
// 1414_FindMinFibonacciNumbers
// 2020-07-12-23:30
// https://leetcode-cn.com/u/joe_zm/


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace name {
	class Solution {
		int findByArray(int k) {
			vector<int> temp;
			temp.push_back(k >> 1);
			temp.push_back(k - (k >> 1));
		}
	};
}
