#include "Solution.h"
#include "list"
using namespace CreateTargetArray;

vector<int> Solution::InsertByList(vector<int>& nums, vector<int>& index) {
	// 8ms, 8.9MB
	list<int> ans = {};
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		auto iter = ans.begin();
		advance(iter, index[i]);
		ans.insert(iter, nums[i]);
	}
	vector<int> ansVec = vector<int>(n);
	int idx = 0;
	for (auto& num : ans) {
		ansVec[idx] = num;
		idx++;
	}
	return ansVec;
}

vector<int> Solution::NotInsert(vector<int>& nums, vector<int>& index) {
	// 4ms, 8.7MB
	for (unsigned i = 1; i < nums.size(); i++) {
		for (unsigned j = 0; j < i; j++) {
			if (index[j] >= index[i])
				index[j]++;
		}
	}
	vector<int> ans = vector<int>(nums.size());
	for (unsigned i = 0; i < nums.size(); i++)
		ans[index[i]] = nums[i];
	return ans;
}

vector<int> Solution::InsertByVector(vector<int>& nums, vector<int>& index) {
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++)
		ans.insert(ans.begin() + index[i], nums[i]);
	return ans;
}
