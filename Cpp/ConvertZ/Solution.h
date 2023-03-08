#pragma once
#include <string>
using namespace std;
class Solution {
    string convert(string s, int numRows) {
        int inteval = (numRows - 1) << 1;
        int n = s.size();
        string ans;
        if(numRows < 2)return s;
        for(size_t i = 0; i < n; i+=inteval) {
            ans += s[i];
        }
        if(numRows > 2) {
            for(int i = numRows - 2; i > 0; i--) {
                int start = numRows - 1;
                for(; start + i < n; start += inteval) {
                    ans += s[start - i];
                    ans += s[start + i];
                }
                if(start - i < n) {
                    ans += s[start - i];
                }
            }
        }
        for(size_t i = numRows-1; i < n; i+=inteval) {
            ans += s[i];
        }
        return ans;
    }
};

