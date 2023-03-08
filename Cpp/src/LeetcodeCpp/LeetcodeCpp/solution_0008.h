#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
class Automaton {
    std::string state = "start";
    std::unordered_map<std::string, std::vector<std::string>> table = {
        {"start",{"start","signed","in_number","end"}},
        {"signed",{"end","end","in_number","end"}},
        {"in_number",{"end","end","in_number","end"}},
        {"end",{"end","end","end","end"}}
    };
    int get_state(char c) {
        if(isspace(c))return 0;
        if(c == '+' || c == '-')return 1;
        if(isdigit(c))return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;
    void get(char c) {
        state = table[state][get_state(c)];
        if(state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? std::min(ans, (long long)INT_MAX) : std::min(ans, (long long)INT_MIN);
        } else if(state == "signed") {
            sign = c == '+' ? 1 : -1;
        }
    }
};
class Solution {
public:
    /**
     * 确定有限状态机（deterministic finite automaton, DFA）
     * 
     * \param str
     * \return 
     */
    int myAtoi(std::string str) {
        Automaton automaton;
        for(char c : str) {
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
    int myAtoiCin(std::string str) {
        std::stringstream liu(str);
        long long n = 0;
        liu >> n;
        return std::min(std::max(n, (long long)INT_MIN), (long long)INT_MAX);
    }
};

