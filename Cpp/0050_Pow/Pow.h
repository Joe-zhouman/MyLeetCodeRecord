// Administrator
// LeetCode
// 0050_Pow
// 2020-12-12-17:26
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
class Solution {
public:
	static double Directly(double x, int n) {
		double ans = 1;
		bool flag = true;
		if (n < 0) { n = -n; flag = false; }
		for (int i = 0; i < n; ++i) { ans = flag ? ans * x : ans / x; }
		return ans;
	}

	static double BitCount(double x, int n) {
		double ans = 1;
		bool flag = true;
		if (n < 0) {
			if (n == INT_MIN) {
				n = -(n + 1);
				ans = 1 / x;
			}
			else { n = -n; }
			flag = false;
		}
		while (n != 0) {
			if (n % 2 == 1) { ans = flag? ans * x:ans/x; }
			x *= x;
			n >>= 1;
		}
		return ans;
	}
};
