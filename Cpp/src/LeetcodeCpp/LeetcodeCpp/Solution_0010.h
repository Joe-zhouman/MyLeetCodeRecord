#pragma once
/*****************************************************************//**
 * \file   Solution_0010.h
 * \brief  ������ʽƥ��
 * ����һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ��������ʽƥ�䡣
 * * '.' ƥ�����ⵥ���ַ�
 * * '*' ƥ���������ǰ�����һ��Ԫ��
 * \author Administrator
 * \date   March 2023
 *********************************************************************/

#include <unordered_set>
#include <string>
class Solution_0010 {

private:
    std::unordered_set<int> current_state_set = {0};
    void update_current_state_set(char str,std::string p) {
        std::unordered_set<int> temp_state_set;
        if(str == '~') {
            for(auto state : current_state_set) {
                temp_state_set.insert(state);
                auto possible_state = state;
                while(possible_state+1<p.size()&&p[possible_state+1]=='*') {
                    possible_state += 2;
                    temp_state_set.insert(possible_state);
                }
            }
        } else {
            for(auto state : current_state_set) {
                if(state >= p.size() || (p[state] != str && p[state] != '.')) {
                    continue;
                }
                if(state + 1 > p.size() && p[state + 1] == '*') {
                    temp_state_set.insert(state);
                } else {
                    temp_state_set.insert(state + 1);
                }
            }
        }
         
    }
public:
    bool isMatch(std::string s, std::string p) {
        update_current_state_set('~',p);
        for(auto c : s) {
            update_current_state_set(c,p);
            update_current_state_set('~', p);
        }
        if(current_state_set.find(p.size())!=current_state_set.end()) {
            return true;
        }
        return false;
    }
};

