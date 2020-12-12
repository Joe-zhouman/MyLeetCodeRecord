// Administrator
// LeetCode-Cpp
// 0069_MySqrt
// 2020-08-01-16:58
// https://leetcode-cn.com/u/joe_zm/
#pragma once
namespace my_sqrt {
    class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0 || x == 1)
                return x;
 
            auto hi = (x >> 1) + 1;
            auto lo = 0;
            while (1 < hi - lo){
	            const auto mi = (hi + lo) >> 1;
	            const auto temp = mi * mi;
                if (temp == x)
                    return mi;
                if (temp < x)
                    lo = mi;
                else
                    hi = mi;
            }
            return lo;
        }
    };
}
