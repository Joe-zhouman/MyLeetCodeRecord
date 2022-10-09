#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
class Solution{
public:
    /**
     * @brief �������ڴ�������ظ��Ӵ�����
     * @param s ����ѯ�ַ���
     * @return �ַ�������
     * @details ʱ�临�Ӷ�:O(N)
     * @details �ռ临�Ӷ�:O(|\f\Sigma\f|)  \f\Sigma\fΪ�ַ����Ĵ�С����ʹ�ù�ϣ������Ķ���ռ䣩
     * @details ����unorder_set����ϣ����¼�ѳ��ֵ��ַ���
     * ����ϣ�����޴���ѯ����˵����ǰ�ַ�δ���֣���ָ�����ƣ���ϣ������Ӹü���
     * ����ϣ�����и�ֵ������ָ��ֹͣ�ƶ���ֹͣ�������Ե�ǰ��ָ��Ϊ������Ӵ�����Ϊright-left+1��
     * ֮�󣬴ӹ�ϣ�����Ƴ���ָ�����ڵļ�����ָ�����ơ�
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
     * @brief �������ڴ�������ظ��Ӵ�����
     * @param s ����ѯ�ַ���
     * @return �ַ�������
     * @details ʱ�临�Ӷ�:O(N)
     * @details �ռ临�Ӷ�:O(|\f\Sigma\f|)\f\Sigma\fΪ�ַ����Ĵ�С����ʹ�ù�ϣ������Ķ���ռ䣩
     * @details ����unorder_set����ϣ����¼�ѳ��ֵ��ַ���
     * ����ϣ�����޴���ѯ����˵����ǰ�ַ�δ���֣���ָ�����ƣ���ϣ������Ӹü���
     * ����ϣ�����и�ֵ������ָ��ֹͣ�ƶ���ֹͣ�������Ե�ǰ��ָ��Ϊ������Ӵ�����Ϊright-left+1��
     * ֮�󣬴ӹ�ϣ�����Ƴ���ָ�����ڵļ�����ָ�����ơ�
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

