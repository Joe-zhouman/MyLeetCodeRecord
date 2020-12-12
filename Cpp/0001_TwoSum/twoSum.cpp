
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
	static vector<int> TwoSumDirectly(vector<int>& nums, int target);
	//872ms 7.2MB
	static vector<int> TwoSumTwoThread(vector<int>& nums, int target);
	//4ms 21.3MB
	static vector<int> TwoSumHashMap(vector<int>& nums, int target);
	//12ms 8.2MB
	static void Merge(vector<int>& nums, int lo, int mi, int hi);

	static void MergeSort(vector<int>& nums, int lo, int hi);

	static void MergeSort(vector<int>& nums) {
		MergeSort(nums, 0, nums.size());
	}

	static int Find(vector<int>& nums, int lo, int hi, int target);

	static int Find(vector<int>& nums,  int target) {
		return Find(nums, 0, nums.size(), target);
	}
};

int main() {
	vector<int> nums = { 2, 3, 15, 3 };
	const auto target = 6;
	auto ans = Solution::TwoSumTwoThread(nums, target);
	for (auto value : ans) {
		cout << value << endl;
	}
	ans = Solution::TwoSumDirectly(nums, target);
	for (auto value : ans) {
		cout << value << endl;
	}
	ans = Solution::TwoSumHashMap(nums, target);
	for (auto value : ans) {
		cout << value << endl;
	}
	return 0;
}

vector<int> Solution::TwoSumDirectly(vector<int>& nums, int target) {
	vector<int> ans;
	for(unsigned i = 0; nums.size() > i; i++)		
		for(unsigned j = 1; nums.size() > j; j++) {
			if(i == j)
				continue;
			if (nums[i] + nums[j] == target) {
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	return ans;
}//直接法

vector<int> Solution::TwoSumTwoThread(vector<int>& nums, int target) {
	vector<int> ans;
	vector<int> sortedNums = nums;
	MergeSort(sortedNums);
	int hi = sortedNums.size() - 1;
	for(int i = 0;i < hi; i++) {
		const int temp = target - sortedNums[i];
		int j = hi;
		while (sortedNums[j] > temp && j > i)
			j--;
		if (j == i)
			return ans;
		if (sortedNums[j] == temp) {
			ans.push_back(Find(nums, sortedNums[i]));
			if (sortedNums[i] != temp)
				ans.push_back(Find(nums, temp));
			else
				ans.push_back(Find(nums, ans[0] + 1, nums.size(), temp));
			return ans;
		}		
		hi = j;
		}
	return ans;
}

vector<int> Solution::TwoSumHashMap(vector<int>& nums, int target) {
	unordered_map<int, int> numHashMap;
	vector<int> ans;
	for (unsigned i = 0; nums.size() > i; i++) {
		auto iter = numHashMap.find(target - nums[i]);
		if (iter != numHashMap.end()) {
			ans.push_back(i);
			ans.push_back(iter->second);
			return ans;
		}
		numHashMap.insert_or_assign(nums[i], i);
	}
	return ans;
}

void Solution::Merge(vector<int>& nums, int lo, int mi, int hi) {
	vector<int> a(nums.begin() + lo, nums.begin() + mi);
	for (int k = lo, j = mi, i = 0; i < mi - lo; k++) {
		nums[k] = (j >= hi || a[i] <= nums[j]) ? a[i++] : nums[j++];
	}
}

void Solution::MergeSort(vector<int>& nums, int lo, int hi) {
	if (hi - lo < 2)
		return;
	int mi = (hi + lo) / 2;
	MergeSort(nums, lo, mi);
	MergeSort(nums, mi, hi);
	Merge(nums, lo, mi, hi);
}

int Solution::Find(vector<int>& nums, int lo, int hi, int target) {
	for (int i = lo; i < hi; i++)
		if (nums[i] == target)
			return i;
	return -1;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
