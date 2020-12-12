// Administrator
// LeetCode-Cpp
// 0007_Reverse
// 2020-07-31-21:12
// https://leetcode-cn.com/u/joe_zm/
#pragma once
constexpr int max_int = 2147483647;//2147483647
constexpr int min_int = -2147483648;//-2147483648
namespace reverse {
    class solution {
    public:
        int reverse(int x) {
	        auto rev = 0;
            while (x != 0) {
	            const auto last_bit = x % 10;
                x /= 10;
                if (max_int / 10 < rev || (max_int / 10 == rev && last_bit > 7))
                    return 0;
                if (rev < min_int / 10 || (rev == min_int / 10 && last_bit < -8))
                    return 0;
                rev = rev * 10 + last_bit;
            }
            return rev;
        }
    };
}
