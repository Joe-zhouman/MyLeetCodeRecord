// Joe
// 周漫
// 2020071822:42


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace trim_mean {
	class Solution {
	public:
		static double average(vector<int>& salary) {
			const auto n = salary.size();
			if (n < 3) return 0;
			auto max_val = salary[0];
			auto min_val = salary[0];
			double sum = salary[0];
			for (auto i = 1; i < n; ++i) {
				if (max_val > salary[i])
					max_val = salary[i];
				if (min_val < salary[i])
					min_val = salary[i];
				sum += salary[i];
			}
			return (sum - max_val - min_val) / (n - 2);
		}
	};
}
