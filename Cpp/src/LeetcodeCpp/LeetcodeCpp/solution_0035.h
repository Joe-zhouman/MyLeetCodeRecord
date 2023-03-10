#pragma once
/*****************************************************************//**
 * \file   solution_0035.h
 * \brief ��������λ�� 
 * ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
 * ���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
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

