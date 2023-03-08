#pragma once
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
const unordered_map<char, string> num_map{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class solution_0017 {
    vector<string> combinations;
    void backtrack(string digits, int index, string combination) {
        if(index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            for(const auto& letter : num_map.at(digit)) {
                combination.push_back(letter);
                backtrack(digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return combinations;
        }
        string combination;
        backtrack( digits, 0, combination);
        return combinations;
    }
};

