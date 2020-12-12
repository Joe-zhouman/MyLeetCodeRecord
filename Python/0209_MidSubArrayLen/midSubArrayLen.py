class Solution:
    def minSubArrayLen(self, s, nums) :
        hi = len(nums)
        sumNums = [0 for i in range(hi)]
        for j in range(hi):           
            for i in range(hi):
                sumNums[i] = sumNums[i]+nums[i+j]
                if  sumNums[i]>= s:
                    return j+1               
            hi = hi - 1
        return 0


a = [2, 3, 6, 2, 4, 3]
s = 7
b = Solution().minSubArrayLen(s,a)
print(b)
