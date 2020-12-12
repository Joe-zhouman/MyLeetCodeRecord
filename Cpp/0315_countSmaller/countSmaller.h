#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace countSmaller {
	class BinIdxTree {
		vector<int> _data;
		int _size;

	public:
		BinIdxTree(int n) : _data(n + 1),
		                    _size(n + 1) { }

		static int lowbit(int x) { return x & (-x); }

		int get(int p) {
			int r = 0;
			for (; p; p -= lowbit(p))
				r += _data[p];
			return r;
		}

		void add(int p, int v) {
			for (; p < _size; p += lowbit(p))
				_data[p] += v;
		}
	};

	class Solution {
	public:
		static vector<int> binIdxTree(vector<int>& nums) {
			auto sorted = nums;
			sort(sorted.begin(), sorted.end());
			auto getId = [&](const int num) { return lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin(); };
			const int n = nums.size(); // NOLINT(clang-diagnostic-sign-conversion)
			BinIdxTree bit(n);
			vector<int> ans(n, 0);
			for (int i = n - 1; i >= 0; --i) {
				auto id = getId(nums[i]);
				ans[i] = bit.get(id);
				bit.add(id + 1, 1);
			}
			return ans;
		}
	};

	class Solution2 {
		vector<int> _index;

		void merge(vector<int>& nums, int lo, int mi, int hi) {
			vector<int> a(nums.begin() + lo, nums.begin() + mi);
			vector<int> ai(_index.begin() + lo, _index.begin() + mi);
			for (int k = lo, j = mi, i = 0; i < mi - lo; k++) {
				if ((j >= hi || a[i] <= nums[j])) {
					nums[k] = a[i];
					_index[k] = ai[i];
					ans[ai[i++]] += j - mi;
				}
				else {
					nums[k] = nums[j];
					_index[k] = _index[j++];
				}
			}
		}

		void mergeSort(vector<int>& nums, int lo, int hi) {
			if (hi - lo < 2)
				return;
			const auto mi = (hi + lo) >> 1;
			mergeSort(nums, lo, mi);
			mergeSort(nums, mi, hi);
			merge(nums, lo, mi, hi);
		}

	public:
		vector<int> ans;

		vector<int> sort(vector<int>& nums) {
			const int n = nums.size();
			for (int i = 0; i < n; ++i) { _index.push_back(i); }
			ans = vector<int>(n, 0);
			mergeSort(nums, 0, n);
			return ans;
		}
	};
}
