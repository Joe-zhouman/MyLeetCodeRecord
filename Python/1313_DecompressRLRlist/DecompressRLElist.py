class Solution:
    def decompressRLElist_1(self, nums: List[int]) -> List[int]:
        # 56ms 13.7MB
        ans = []
        for i in range(len(nums)//2):
            for j in range(nums[2*i]):
                ans.append(nums[2*i+1])
        return ans

    def decompressRLElist_2(self, nums: List[int]) -> List[int]:
        # 40ms
        ans = []
        for i in range(len(nums)//2):
            ans += (nums[2*i+1] for j in range(nums[2*i]))
        return ans
