class Solution:
    def runningSum(self, nums):
        ans = []
        sum = 0
        for num in nums:
            sum += num
            ans.append(sum)
        return ans


nums = [1, 2, 3, 4]
ans = Solution().runningSum(nums)
for num in ans:
    print(num)
