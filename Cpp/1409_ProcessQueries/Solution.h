#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace ProcessQueries {
	class BinIdxTree {
		vector<int> _data;
		int _size;
	public:
		BinIdxTree(int n) : _data(n + 1),
		                    _size(n + 1) {}

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
		static void MoveToBegin(vector<int>& arr, int idx) {
			const auto temp = arr[idx];
			for (auto i = idx; i > 0; i--) { arr[i] = arr[i - 1]; }
			arr[0] = temp;
		}

	public:
		static vector<int> Directly(vector<int>& queries, int m) {
			vector<int> ans = {};
			vector<int> index;
			index.reserve(m);
			for (auto i = 0; i < m; i++)
				index.push_back(i + 1);
			for (int query : queries) {
				auto idx = find(index.begin(), index.end(), query) - index.begin();
				ans.push_back(idx);
				MoveToBegin(index, idx);
			}
			return ans;
		}

		static vector<int> Bit(vector<int>& queries, int m) {
			vector<int> ans = {};
			int n = queries.size();
			BinIdxTree bit(m + n);
			vector<int> position(m);
			for (int i = 0; i < m; ++i) {
				position[i] = n + i + 1;
				bit.add(n + i + 1, 1);
			}
			for (auto i = 0; i < n; ++i) {
				int& id = position[queries[i] - 1];
				bit.add(id, -1);
				ans.push_back(bit.get(id));
				id = n - i;
				bit.add(id, 1);
			}
			return ans;
		}
	};
}
