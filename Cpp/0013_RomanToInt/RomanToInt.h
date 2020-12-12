// Administrator
// LeetCode-Cpp
// 0013_RomanToInt
// 2020-07-31-21:59
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <string>
#include <unordered_map>

namespace roman_to_int {
    class solution {
    public:

	    static int hash_set(std::string s) {
            std::unordered_map<char, int> char_to_num = 
            { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };  
            if (s.size() == 1)
                return char_to_num[s[0]];
            auto ans = 0;
            auto last_num = 1000;
            for(auto c:s) {
                auto num = char_to_num[c];
                ans += num;
                if (num > last_num)
                    ans -= last_num * 2;
                last_num = num;
            }
            return ans;
        }

        static int f_switch(std::string s) {
            if (s.size() == 1)
                return f_char_to_num(s[0]);
            auto ans = 0;
            auto last_num = 1000;
            for (auto c : s) {
	            const auto num = f_char_to_num(c);
                ans += num;
                if (num > last_num)
                    ans -= last_num * 2;
                last_num = num;
            }
            return ans;
        }
        static int f_char_to_num(char c) {
	        switch (c) {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
	        }
        }
    };
}
