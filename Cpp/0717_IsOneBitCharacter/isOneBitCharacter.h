// Joe
// 周漫
// 2020080617:30


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace is_one_bit_character {
	class Solution {
	public:
		bool IsOneBitCharacter(vector<int>& bits) {
			int n = bits.size();
			int i = 0;
			while (i<n-1) {
				i += bits[i] + 1;
			}
			return i == n - 1;
		}
	};
}
