// Administrator
// LeetCode-Cpp
// 0014_LongestCommonPrefix
// 2020-08-01-16:17
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <vector>
#include <string>

namespace longest_common_prefix {
    class solution {
    public:
        static std::string char_by_char(std::vector<std::string>& strs) {
            std::string ans;
            const auto n_str = strs.size();
            if (n_str == 0)return ans;
            if (n_str == 1)return strs[0];
            auto min_len = strs[0].size();
            for (const auto& str : strs) {
                if (str.size() < min_len)
                    min_len = str.size();
            }
            if (min_len == 0) return ans;
            for (int i = 0; i < min_len; ++i) {
	            for (int j = 1; j < n_str ; ++j) {
                    if (strs[j][i] != strs[j - 1][i])
                        return ans;
	            }
                ans += strs[0][i];
            }
            return ans;
        }
    	static std::string recursion(std::vector<std::string>& strs) {
            if (strs.empty())
                return "";
            if (strs.size() == 1)
                return strs[0];
        	if
        }
    };
}
