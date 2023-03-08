#pragma once
#include <vector>
using namespace std;
class Solution {
private:
    /**
     * @brief 寻找两个数组中第k大的数。
     * @param nums1 第一个数组
     * @param nums2 第二个数组
     * @param k 
     * @return 第k大的数。
     * @details 比较A[size>>1]和B[size>>1]。
     * @details 若A[size>>1] <= B[size>>1], 则A[0,size>>1)均不可能是第k大的数。
     * @details 若A[size>>1] > B[size>>1], 则B[0,size>>1)均不可能是第k大的数。
     * @若A[size>>1]或B[size>>1]越界，比如A只剩一个元素，但k=4，此时选取A中最后一个元素而非A[size>>1]。
    */
    int FindMinK(const vector<int>& nums1, vector<int>& nums2,int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0; 
        int index2 = 0;
        while(true) {
            if(m == index1) {
                return nums2[index2 + k - 1];
            }
            if(n == index2) {
                return nums1[index1 + k - 1];
            }
            if(1 == k) {
                return min(nums1[index1], nums2[index2]);
            }
            int new_index_1 = min(index1 + (k >> 1) - 1, m - 1);
            int new_index_2 = min(index2 + (k >> 1) - 1, n - 1);
            if(nums1[new_index_1] <= nums2[new_index_2]) {
                k -= new_index_1 - index1 + 1;
                index1 = new_index_1 + 1;
            }
            else {
                k -= new_index_2 - index2 + 1;
                index2 = new_index_2 + 1;
            }
        }
    }

public:
    /**
     * @brief 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
     *        返回这两个正序数组的 中位数 。
     * @param nums1 第一个数组
     * @param nums2 第二个数组
     * @return 中位数
     * @details 对于两个数组总元素数量n为奇数的情况，即返回第(n+1)/2大的数。
     * @details 对于两个数组总元素数量n为偶数的情况，即返回第n/2大的数和第n/2+1大的数的平均值。
     * @details 时间复杂度 O(log(m+n))
     * @details 空间复杂度 O(1)
    */
    double BinSearch(vector<int>& nums1, vector<int>& nums2) {
        int total_length = nums1.size() + nums2.size();
        if(1 == total_length % 2) {
            return FindMinK(nums1, nums2, (total_length + 1) >> 1);
        }
        else {
            return (FindMinK(nums1, nums2, total_length >> 1) + FindMinK(nums1, nums2, (total_length >> 1) + 1)) / 2.0;
        }
    }
    double Traval(vector<int>& nums1,int m, vector<int>& nums2,int n) {
        int left = -1, right = -1;
        int aStart = 0, bStart = 0;
        for(int i = 0; i <= (m+n)>>1; i++) {
            left = right;
            if(aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
                right = nums1[aStart++];
            } else {
                right = nums2[bStart++];
            }
        }
        if(0 == ((m + n) & 1)) {
            return (left + right) / 2.0;
        }
        return right;
    }
    /**
     * @brief 分割法求中位数
     * @param nums1 
     * @param nums2 
     * @return 
     * @details  将A分成A_left和和A_right, B划分成B_left和B_right。
     * @details 若m+n为偶数, 且length(A_left+B_left)=length(A_right+B_right),
     * @details max(A_left+B_left)<=min(A_right+B_right),
     * @details 则中位数为 (max(A_left+B_left)+min(A_right+B_right))/2.
     * @details 若m+n为奇数, 且length(A_left+B_left)=length(A_right+B_right)+1,
     * @details max(A_left+B_left)<=min(A_right+B_right),
     * @details 则中位数为 max(A_left+B_left).
     * @details 时间复杂度 O(log(min(m,n)))
     * @details 空间复杂度 O(1)
    */
    double TrimArray(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return TrimArray(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        if(m + n < 6) {
            return Traval(nums1, m, nums2, n);
        }
        int left = 0;
        int right = m;
        int median1 = 0;
        int median2 = 0;
        while(left <= right) {
            int i = (left + right) >> 1;
            int j = ((m + n + 1) >> 1) - i;
            if(0 != j && m != i && nums1[i] < nums2[j - 1]) {
                left = i + 1;
            } else if(0 != i && n != j && nums1[i - 1] > nums2[j]) {
                right = i - 1;
            }
            else {
                if(0 == i) { median1 = nums2[j - 1]; }
                else if(j == 0) { median1 = nums1[i - 1]; }
                else { median1 = max(nums1[i - 1], nums2[j - 1]); }
                if(1 == (m + n) % 2) { return median1; }

                if(m == i) { median2 = nums2[j]; }
                else if(n == j) { median2 = nums1[i]; }
                else { median2 = min(nums1[i], nums2[j]); }
                return (median1 + median2) / 2.0;
            }
        }
        return 0.0;
    }
};
