// Administrator
// LeetCode-Cpp
// 0071_SimplifyPath
// 2020-07-25-21:40
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	static vector<string> split(string str) {
		vector<string> str_vector;
		string t;
		for (auto c : str) {
			if(c == '/'&& !t.empty()) {
				str_vector.push_back(t);
				t = "";
			}
			else if(c != '/') {
				t += c;
			}
		}
		if(!t.empty()) {
			str_vector.push_back(t);
		}
		return str_vector;
	}
	static string SplitStringStream(string path) {
		vector<string> str_vector;
		string t;
		istringstream str_stream(path);
		while (getline(str_stream,t,'/')) {
			if(t == ".."&&!str_vector.empty()) {
				str_vector.pop_back();
			}
			else if(t!=""&&t!="."&&t!="..") {
				str_vector.push_back(t);
			}
		}
		if(str_vector.empty()) {
			return "/";
		}
		string ans;
		for (auto i = 0; i < str_vector.size(); ++i) {
			ans.append("/");
			ans.append(str_vector[i]);
		}
		return ans;
	}
	static string simplifyPath(string path) {
		auto dirs = split(path);
		stack<string> dir_stack;
		for (auto dir : dirs) {
			if(dir == ".."&& !dir_stack.empty()) {
				dir_stack.pop();
			}
			else if(dir != ".."&&dir!=".") {
				dir_stack.push(dir);
			}
		}		
		if(dir_stack.empty()) {
			return "/";
		}
		string ans;
		while (!dir_stack.empty()){
			ans = "/" + dir_stack.top() + ans;
			dir_stack.pop();
		}
		return ans;
	}
};
