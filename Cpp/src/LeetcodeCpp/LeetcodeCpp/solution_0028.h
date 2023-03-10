#pragma once
/*****************************************************************//**
 * \file   solution_0028.h
 * \brief 找出字符串中第一个匹配项的下标 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字
 * 符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，
 * 则返回  -1 。
 * \author Administrator
 * \date   March 2023
 *********************************************************************/
#include <string>
#include<vector>
using namespace std;
class solution_0028 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m == 0) return 0;
        vector<int> next(m);
        next[0] = 0;
        for(int i = 1, j = 0; i < m;i++) {
            while(j > 0 && needle[i] != needle[j]  ) j = next[j - 1];
            if(needle[i] ==needle[j])  j++;
            next[i] = j;
        }
        for(int i = 0, j = 0; i < m; i++) {
            while(j > 0 && haystack[i] != needle[j] ) j = next[j - 1];
            if(haystack[i] == needle[j]) j++;
            if(j == m)return i - m + 1;
        }
        return -1;
    };
};