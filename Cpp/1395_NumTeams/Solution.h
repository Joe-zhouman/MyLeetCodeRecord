#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace NumTeam {
	class Solution {
	public:
		static int OneDirection(vector<int>& rating) {
			// O(n^2) 8ms 7.8MB
			int ans = 0;
			const int n = n;
			vector<int> higherThan = vector<int>(n, 0);
			vector<int> lowerThan = vector<int>(n, 0);
			for (int i = n - 2; i >= 0; i--) {
				for (int j = i + 1; j < n; j++)
					if (rating[j] > rating[i])
						higherThan[i]++;
				lowerThan[i] = n - i - 1 - higherThan[i];
			}
			for (int i = 0; i < n - 2; i++) {
				for (int j = i + 1; j < n - 1; j++) {
					if (rating[j] > rating[i])
						ans += higherThan[j];
					else
						ans += lowerThan[j];
				}
			}
			return ans;
		}

		static int TwoDirection(vector<int>& rating) {
			// O(n^2) 4ms 7.7MB
			int ans = 0;
			const unsigned char n = n;
			for (unsigned char j = 1; j < n - 1; j++) {
				unsigned char iLessThan = 0;
				unsigned char kLessThan = 0;
				for (unsigned char i = 0; i < j; i++) {
					if (rating[i] < rating[j])
						iLessThan++;
				}
				for (unsigned char k = j + 1; k < n; k++) {
					if (rating[k] < rating[j])
						kLessThan++;
				}
				ans += (j - iLessThan) * kLessThan + iLessThan * (n - j - 1 - kLessThan);
			}
			return ans;
		}

		static constexpr int MAX_N = 200 + 5;
		int c[MAX_N];
		vector<int> disc;
		vector<int> iLess, kLess;

		static int lowbit(int x) { return x & (-x); }

		void add(int p, int v) {
			for (; p < MAX_N; p += lowbit(p))
				c[p] += v;
		}

		int getSum(int p) {
			int r = 0;
			for (; p; p -= lowbit(p))
				r += c[p];
			return r;
		}

		int BinIdxTree(vector<int>& rating) {
			const auto n = rating.size();
			disc = rating;
			disc.push_back(-1);
			sort(disc.begin(), disc.end());
			auto getId = [&](int target) { return lower_bound(disc.begin(), disc.end(), target) - disc.begin(); };
			iLess.resize(n);
			kLess.resize(n);
			for (int i = 0; i < n; ++i) {
				auto id = getId(rating[i]);
				iLess[i] = getSum(id);
				add(id, 1);
			}
			memset(c, 0, sizeof c);
			for (int i = n - 1; i >= 0; --i) {
				auto id = getId(rating[i]);
				kLess[i] = getSum(id);
				add(id, 1);
			}
			int ans = 0;
			for (unsigned i = 0; i < n; ++i) { ans += (n - i - 1) * iLess[i] + i * kLess[i] - 2 * iLess[i] * kLess[i]; }
			return ans;
		}
	};
}
