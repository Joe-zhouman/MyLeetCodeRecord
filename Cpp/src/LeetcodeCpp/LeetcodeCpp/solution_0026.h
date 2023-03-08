#pragma once
#include<vector>
using namespace std;
class solution_0026 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int current_pos = 0;
        int current_num = nums[0];
        for(size_t i = 1; i < nums.size(); i++) {
            if(nums[i] == current_num) continue;
            current_pos++;
            current_num = nums[i];
            nums[current_pos] = current_num;
        }
        return current_pos + 1;
    }
};

