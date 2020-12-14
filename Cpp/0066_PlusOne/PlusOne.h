// Administrator
// LeetCode
// 0066_PlusOne
// 2020-12-14-15:09
// *Author*    : Joe, Zhou Man 
// *Email*     : man.man.man.man.a@gmail.com 
// *Email*     : joe_zhouman@foxmail.com 
// *QQ*        : 1592020915 
// *Weibo*     : @zhouman_LFC 
// *Twitter*   : @zhouman_LFC 
// *Website*   : www.joezhouman.com 
// *Github*    : https://github.com/Joe-zhouman 
// *LeetCode*  : https://leetcode-cn.com/u/joe_zm/

#pragma once
#include <vector>

class Solution {
public:
	static std::vector<int> PlusOne(std::vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; --i) {
			if(9 == (digits[i])) {
				digits[i] = 0;
			}
			else {
				digits[i] ++;
				return digits;
			}
			
		}
		digits = std::vector<int>(digits.size() + 1);
		digits[0] = 1;
		return digits;
    }
};
