#pragma once
#include <vector>
using namespace std;

namespace ProductExceptSelf {
	class Solution {
	public:
		static vector<int> Directly(vector<int>& nums) {
			int n = nums.size();
			vector<int> ans(n, 1);
			int rightMul = 1;
			for (int i = 1; i < n; ++i) { ans[i] = nums[i - 1] * ans[i - 1]; }
			for (int i = n - 2; i >= 0; --i) {
				rightMul *= nums[i + 1];
				ans[i] *= rightMul;
			}
			return ans;
		}
	};
}
