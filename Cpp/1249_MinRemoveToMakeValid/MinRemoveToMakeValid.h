// Administrator
// LeetCode-Cpp
// 1249_MinRemoveToMakeValid
// 2020-07-26-21:25
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <string>
#include <stack>
#include <sstream>
class Solution {
public:
    std::string min_remove_to_make_valid(std::string s) {
		std::stack<std::pair<char, int>> opt;
	    for (auto i = 0; i < s.size(); ++i) {
			auto t = s[i];
		    if(t == '(') {
				opt.push({ t,i });
		    }
	    	else if(t == ')') {
	    		if(!opt.empty()&&opt.top().first == '(') {
					opt.pop();
	    		}
	    		else {
					opt.push({ t,i });
	    		}
	    	}
	    }

		while (!opt.empty()) {
			s.erase(s.begin()+opt.top().second);
			opt.pop();
		}
		return s;
    }
};