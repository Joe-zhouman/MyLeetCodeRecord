#pragma once
#include <vector>
using namespace std;

namespace CreateTargetArray {
	class Solution {
		static vector<int> InsertByList(vector<int>& nums, vector<int>& index);
		static vector<int> NotInsert(vector<int>& nums, vector<int>& index);
		static vector<int> InsertByVector(vector<int>& nums, vector<int>& index);
	};
}
