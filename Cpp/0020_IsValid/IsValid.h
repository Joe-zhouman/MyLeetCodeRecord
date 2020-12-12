// Administrator
// LeetCode-Cpp
// 0020_IsValid
// 2020-07-25-20:46
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <stack>
#include <string>
using namespace std;

namespace is_valid {
	class Solution {
		static bool isLeft(const char c) { return c == '(' || c == '{' || c == '['; }

		static bool isPair(char c, char t) {
			return (c == ')' && t == '(') || (c == ']' && t == '[') || (c == '}' && t == '{');
		}

	public:
		static bool isValid(string s) {
			stack<char> opt;
			for (char c : s) {
				if (isLeft(c)) { opt.push(c); }
				else {
					if (opt.empty() || !isPair(c, opt.top())) { return false; }
					opt.pop();
				}
			}
			return opt.empty();
		}
	};
}
