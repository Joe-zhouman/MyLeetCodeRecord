// Joe
// 周漫
// 2020082023:26


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace getSkyline {
	class Solution {
	public:
		vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
			long n = 1 + buildings.back()[1];
			vector<int>max_height(n);
			for (auto building : buildings) {
				for(int j = building[0];j<=building[1];++j) {
					if (max_height[j] < building[2])
						max_height[j] = building[2];
				}
			}
			vector<vector<int>>ans;
			if (max_height[0] != 0)
				ans.push_back({ 0,max_height[0] });
			for (int i = 1; i < n - 2; ++i) {
				if (max_height[i - 1] < max_height[i])
					ans.push_back({ i,max_height[i] });
				if (max_height[i + 1] < max_height[i])
					ans.push_back({ i,max_height[i + 1] });
				
			}
			if (max_height.back() != 0)
				ans.push_back({ n - 1,0});
			return ans;
		}
	};
}
