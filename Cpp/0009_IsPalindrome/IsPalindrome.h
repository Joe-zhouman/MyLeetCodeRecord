// Administrator
// LeetCode-Cpp
// 0009_IsPalindrome
// 2020-07-31-21:36
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <vector>
namespace is_palindrome {
    class solution {
    public:
        bool is_palindrome(int x) {
            if (x < 0)
                return false;
            if (x < 10)
                return true;
            if (!(x % 10))
                return false;
            auto rev = 0;
            while (x > rev) {
                rev = rev * 10 + x % 10;
                x /= 10;
            }
            return x == rev || x == rev / 10;
        }
    };
}
