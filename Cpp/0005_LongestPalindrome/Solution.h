#pragma once
#include<string>
#include<vector>
#include<utility>
using namespace std;
/**
 * @brief 5. ������Ӵ�
 * @details ����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
 * @example ���룺s = "babad"
 * @example �����"bab"
 * @example ���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�
 * @example ���룺s = "cbbd"
 * @example �����"bb"
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
     * @brief ���ö�̬�滮���
     * @param s 
     * @return 
     * @details ����С�ڵ���1���ַ������ǻ��Ĵ���P(i,i)=true
     * @details ����Ϊ2���ַ�����������ĸ��ͬ����Ϊ���Ĵ�P(i,i+1)=(s[i]==s[i+1]);
     * @details ���ȴ���2���ַ����������ұ߽��ַ���������ಿ��Ϊ���Ĵ�����Ϊ���Ĵ���P(i,j)=P(i+1,j-1)&&s[i]==s[j]
     * @details �����ǰ����Ϊ����ΪL���ַ�������Ϊ����ΪL-2���ַ���(L-2>max_len)�򲻿����г�ΪL�Ļ��Ĵ������Ĵ���󳤶�Ϊmax_len��ѭ����ǰ��ֹ��
     * @details ʱ�临�Ӷ�O(n^2)
     * @details �ռ临�Ӷ�O(n^2)
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
     * @brief ������չ��
     * @param s 
     * @return 
     * @details ��ÿ��λ��s[i,i]��s[i,i+1]��ʼ��������չ��
     * @details ʱ�临�Ӷ�O(n^2)
     * @details �ռ临�Ӷ�O(n^2)
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
     * @brief Manacher�㷨
     * @param s 
     * @return 
     * @details ����֮ǰ������չʱ����Ϣ��
     * @details ����Ϊiʱ��s[i-l1]==s[i+l1],����Ϊjʱ��s[j-l2]==s[j+l2]��
     * @details ����ʱ����Ϊ(2j-i),����i����j�Գƣ����е�j-l2==i-l1
     * @details s[j+l2]=s[2j-i+l1]
     * @details ����s[i+l1]==s[j-l2+2l1]==s[j+l2-2l1]==s[2j-i-l1]
     * @details ��s[j+l2]==s[j-l2]==s[i-l1]==s[i+l1]
     * @details �����s[2j-i+l1]==s[2j-i-l1],�˴������жϡ�
     * @details ���㷨ֻ������������ȵ��ַ�����ͨ�����ַ����Ŀ�ͷ�ͽ�β��ÿ�����ַ�֮�����ͬһ���ַ����������ַ�����Ϊ�����ε��ַ�����
     * @details ���յĴ𰸾�Ϊ���������ַ����������������ɡ�
     * @details ʱ�临�Ӷ�O(n)
     * @details �ռ临�Ӷ�O(n)
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

