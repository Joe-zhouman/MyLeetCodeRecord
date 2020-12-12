// Administrator
// LeetCode-Cpp
// 0171_TitleToNumber
// 2020-08-02-22:24
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <string>

namespace title_to_number {
    class Solution {
    public:
        int titleToNumber(std::string s) {
            int ans = 0;
            for (auto c : s) {
                auto t = c - 'A' + 1;
                ans = ans * 26 + t;
            }
            return ans;
        }
    };
}
