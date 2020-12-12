class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        num = start
        ans = start
        for i in range(1, n):
            num += 2
            ans ^= num
        return ans
