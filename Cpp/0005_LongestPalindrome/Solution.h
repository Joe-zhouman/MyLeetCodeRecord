#pragma once
#include<string>
#include<vector>
#include<utility>
using namespace std;
/**
 * @brief 5. 最长回文子串
 * @details 给你一个字符串 s，找到 s 中最长的回文子串。
 * @example 输入：s = "babad"
 * @example 输出："bab"
 * @example 解释："aba" 同样是符合题意的答案。
 * @example 输入：s = "cbbd"
 * @example 输出："bb"
*/
class Solution {
private:
    pair<int, int> ExpandAroundCenter(const string& s, int left, int right) {
        while(0 <= left && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1,right - 1};
     }
public:
    /**
     * @brief 利用动态规划求解
     * @param s 
     * @return 
     * @details 长度小于等于1的字符串必是回文串。P(i,i)=true
     * @details 长度为2的字符串，若两字母相同，其为回文串P(i,i+1)=(s[i]==s[i+1]);
     * @details 长度大于2的字符串，若左右边界字符相等且其余部分为回文串，则为回文串。P(i,j)=P(i+1,j-1)&&s[i]==s[j]
     * @details 如果当前检查的为长度为L的字符串，若为长度为L-2的字符串(L-2>max_len)则不可能有长为L的回文串，回文串最大长度为max_len，循环提前终止。
     * @details 时间复杂度O(n^2)
     * @details 空间复杂度O(n^2)
    */
    string DynamicProgramming(string s) {
        int n = s.size();
        if(n < 2) {
            return s;
        }
        int max_len = 1;
        int begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(size_t i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for(size_t l = 2; l <= n; l++) {
            int i = 0;
            int j = 0;
            for(; i < n; i++) {
                j = l + i - 1;
                if(j >= n) {
                    break;
                }
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if(j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
            if(j - i - max_len > 0) {
                return s.substr(begin, max_len);
            }
        }
        return s.substr(begin, max_len);
    }
    /**
     * @brief 中心扩展法
     * @param s 
     * @return 
     * @details 从每个位置s[i,i]和s[i,i+1]开始向两边扩展。
     * @details 时间复杂度O(n^2)
     * @details 空间复杂度O(n^2)
    */
    string Expand(string s) {
        int start = 0;
        int end = 0;
        for(size_t i = 0; i < s.size(); i++) {
            auto p1 = ExpandAroundCenter(s, i, i);
            auto p2 = ExpandAroundCenter(s, i, i + 1);
            if(p1.second - p1.first > end - start) {
                start = p1.first;
                end = p1.second;
            }                   
            if(p2.second - p2.first > end - start) {
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
    /**
     * @brief Manacher算法
     * @param s 
     * @return 
     * @details 利用之前中心扩展时的信息。
     * @details 中心为i时有s[i-l1]==s[i+l1],中心为j时有s[j-l2]==s[j+l2]。
     * @details 若此时中心为(2j-i),及和i关于j对称，则有当j-l2==i-l1
     * @details s[j+l2]=s[2j-i+l1]
     * @details 另有s[i+l1]==s[j-l2+2l1]==s[j+l2-2l1]==s[2j-i-l1]
     * @details 而s[j+l2]==s[j-l2]==s[i-l1]==s[i+l1]
     * @details 则必有s[2j-i+l1]==s[2j-i-l1],此处无需判断。
     * @details 此算法只能针对奇数长度的字符串，通过在字符串的开头和结尾及每两个字符之间添加同一个字符，将所有字符串变为奇数次的字符串。
     * @details 最终的答案均为奇数次字字符串，不输出奇数项即可。
     * @details 时间复杂度O(n)
     * @details 空间复杂度O(n)
    */
    string Manacher(string s) {
        int start = 0;
        int end = -1;
        string t = "#";
        for(char c : s) {
            t += c;
            t += '#';
        }
        t += '#';
        vector<int>arm_len;
        int right = -1;
        int j = -1;
        for(int i = 0; i < t.size(); i++){
            int current_arm_len;
            if(right >= i) {
                int i_sym = 2 * j - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                auto p = ExpandAroundCenter(t, i - min_arm_len, i + min_arm_len);
                current_arm_len = (p.second - p.first) >> 1;
            } else {
                auto p = ExpandAroundCenter(t, i, i);
                current_arm_len = (p.second - p.first) >> 1;
            }
            arm_len.emplace_back(current_arm_len);
            if(i + current_arm_len > right) {
                j = i;
                right = i + current_arm_len;
            }
            if(current_arm_len * 2 + 1 > end - start) {
                start = i - current_arm_len;
                end = i + current_arm_len;
            }
        }
        string ans;
        for(size_t i = start+1; i <= end; i+=2) {
            ans += t[i];
        }
        return ans;
    }
};

