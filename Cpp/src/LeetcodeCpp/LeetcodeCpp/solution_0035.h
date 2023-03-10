#pragma once
/*****************************************************************//**
 * \file   solution_0035.h
 * \brief 搜索插入位置 
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * \author Administrator
 * \date   March 2023
 *********************************************************************/
#include<vector>
using namespace std;
class solution_0035 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)return 0;
        int lb = 0, ub = n;
        int mid;
        while(ub - lb >0) {
            mid = (lb + ub) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) ub = mid;
            else lb = mid;
        }
        return nums[lb] > target ? lb : lb+1;
    }
};

