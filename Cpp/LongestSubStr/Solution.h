#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
class Solution{
public:
    /**
     * @brief 滑动窗口处理最长无重复子串问题
     * @param s 待查询字符串
     * @return 字符串长度
     * @details 时间复杂度:O(N)
     * @details 空间复杂度:O(|\f\Sigma\f|)  \f\Sigma\f为字符集的大小（即使用哈希表所需的额外空间）
     * @details 利用unorder_set（哈希表）记录已出现的字符。
     * 若哈希表内无带查询键，说明当前字符未出现，右指针右移，哈希表内添加该键。
     * 若哈希表内有该值，则右指针停止移动，停止计数，以当前左指针为起点的最长子串长度为right-left+1。
     * 之后，从哈希表内移除左指针所在的键，左指针右移。
    */
    int HashSet(std::string s) {
        std::unordered_set<char> occured_char;
        int n = s.size();
        int right = -1;
        int ans = 0;
        for (int left = 0; left < n; ++left) {
            if (0 != left) {
                occured_char.erase(s[left - 1]);
            }
            while (right+1<n&&!occured_char.count(s[right+1])){
                occured_char.insert(s[right + 1]);
                right++;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
    /**
     * @brief 滑动窗口处理最长无重复子串问题
     * @param s 待查询字符串
     * @return 字符串长度
     * @details 时间复杂度:O(N)
     * @details 空间复杂度:O(|\f\Sigma\f|)\f\Sigma\f为字符集的大小（即使用哈希表所需的额外空间）
     * @details 利用unorder_set（哈希表）记录已出现的字符。
     * 若哈希表内无带查询键，说明当前字符未出现，右指针右移，哈希表内添加该键。
     * 若哈希表内有该值，则右指针停止移动，停止计数，以当前左指针为起点的最长子串长度为right-left+1。
     * 之后，从哈希表内移除左指针所在的键，左指针右移。
     */
    int HashMap(std::string s) {
      std::unordered_map<char,int> occured_char;
      int n = s.size();
      if (n < 1) return 0;
      int left = 0;
      int right = 1;
      int ans = 1;
      occured_char.insert({s[0],0});
      while (left < right && right < n) {
          if (occured_char.count(s[right]) && occured_char[s[right]] >= left) {
              left = occured_char[s[right]] + 1;
          }
          ans = std::max(ans, right - left + 1);
          occured_char.insert_or_assign(s[right], right);
          right++;
      }
      return ans;
    }
};

