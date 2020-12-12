class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxCount = 0
        maxChar = ''
        for char in s:
            a = s.count(char)
            if a > maxCount:
                maxCount = a
                maxChar = char
        strList = s.split(maxChar)
        longest = 0
        for substr in strList:
            if len(substr) > longest:
                longest = len(substr)
        return longest + 1


s = "abcabcbb"
print(Solution().lengthOfLongestSubstring(s))
