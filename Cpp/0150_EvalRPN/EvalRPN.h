// Administrator
// LeetCode-Cpp
// 0150_EvalRPN
// 2020-07-26-20:46
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <vector>
#include <stack>
#include <string>
#include <sstream>
class solution {
public:
    int eval_rpn(std::vector<std::string>& tokens) {
        std::stack<int> ans;
        for (auto i = 0; i < tokens.size(); ++i) {
            auto t = tokens[i];
	        if(t == "+") {
		        const auto num1 = ans.top();
                ans.pop();
		        const auto num2 = ans.top();
                ans.pop();
                ans.push(num2 + num1);
	        }
        	else if(t == "-") {
		        const auto num1 = ans.top();
                ans.pop();
		        const auto num2 = ans.top();
                ans.pop();
                ans.push(num2 - num1);
        	}
        	else if(t == "*") {
		        const auto num1 = ans.top();
                ans.pop();
		        const auto num2 = ans.top();
                ans.pop();
                ans.push(num2 * num1);
        	}
            else if(t == "/") {
                const auto num1 = ans.top();
                ans.pop();
                const auto num2 = ans.top();
                ans.pop();
                ans.push(num2 / num1);
            }
            else {
                int num;
                std::stringstream s;
                s << t;
                s >> num;
                ans.push(num);
            }
        }
        return ans.top();
    }
};