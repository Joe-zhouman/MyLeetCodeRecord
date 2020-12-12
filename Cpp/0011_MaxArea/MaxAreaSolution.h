#pragma once
#include <algorithm>
#include <vector>
using namespace std; // NOLINT(clang-diagnostic-header-hygiene)

// NO																																																																								LINT(clang-diagnostic-header-hygiene)
namespace maxArea {
	class solution {
	public:
		static int directly(vector<int>& height) {
			auto ans = 0;
			const unsigned n = height.size(); // NOLINT(clang-diagnostic-sign-conversion)
			for (auto i = 0; i < n - 1; ++i) {
				for (auto j = 0; j < n; ++j) {
					const auto area = (j - i) * min(height[i], height[j]);
					if (ans < area)
						ans = area;
				}
			}
			return ans;
		}

		static int twoThread(vector<int>& height) {
			auto ans = 0;
			auto i = 0;
			int j = height.size() - 1;
			while (i < j) {
				int area;
				if (height[i] < height[j]) {
					area = (j - i) * height[i];
					i++;
				}
				else {
					area = (j - i) * height[j];
					j--;
				}
				if (ans < area)
					ans = area;
			}
			return ans;
		}
	};
}
