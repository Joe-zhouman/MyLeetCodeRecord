// Joe
// 周漫
// 2020080620:09


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace number_of_steps {
	class Solution {
		int NumberOfSteps(int num) {
			int ans = 0;
			while (num) {
				if (num % 2) {
					ans++;
				}
				num >>= 1;
				ans++;
			}
			return ans;
		}
	};
}
