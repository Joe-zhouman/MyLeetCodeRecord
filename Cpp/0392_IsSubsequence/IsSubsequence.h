// Joe
// 周漫
// 2020072723:51


#pragma once
#include <algorithm>
#include <vector>
#include <string>

namespace is_subsequence {
	class solution {
	public:
		static bool two_thread(std::string s, std::string t) {
			auto s_idx = 0;
			auto t_idx = 0;
			while (s_idx < s.size() && t_idx < t.size())
			{
				if(s[s_idx] == t[t_idx]) {
					s_idx++;
				}
				t_idx++;
			}
			return s_idx == s.size();
		}
		static bool dynamic_programming(std::string s, std::string t) {
			auto m = t.size();
			std::vector<std::vector<int>> query_form(m+1,std::vector<int>(26));
			for (int i = 0; i < 26; ++i) {
				query_form[m][i] = m;
			}
			for (int i = m - 1; i >= 0; --i) {
				for (auto j = 0; j < 26; ++j) {
					if(t[i] == j+'a') {
						query_form[i][j] = i;
					}
					else {
						query_form[i][j] = query_form[i + 1][j];
					}
				}
			}
			auto pos = 0;
			for (auto i : s) {
				const auto temp = query_form[pos][i - 'a'];
				if(temp == m) {
					return false;
				}
				pos = temp + 1;
			}
			return true;
		}
	};
}
