class Solution:
    ## O(n^2)
    def twoSumDirectly(self, nums, target):
        ## 3360ms 14.8MB
        for i in range(len(nums)):
            a = target - nums[i]
            for j in range(i+1, len(nums)):
                if nums[j] == a:
                    return [i,j]
        return []

    def twoSumSortedReserve(self, nums, target):
        ## 64-68ms 14.6MB
        sortedNums = sorted(nums)
        hi = len(nums)-1
        i = 0
        while i < hi:
            a = target - sortedNums[i]
            for j in range(hi,i,-1):
                if sortedNums[j] == a:
                    idx1 = nums.index(sortedNums[i])
                    if a == target/2:                  
                        idx2 = nums.index(a,idx1+1)
                    else:
                        idx2 = nums.index(a)
                    return [idx1,idx2]
                if sortedNums[j-1] < a:
                    hi = j
                    break
            i = i+1
        return []
    def twoSumHash(self, nums, target):
        ## 64ms 15.1MB
        hashset = {}
        for i in range(len(nums)):
            if hashset.get(target-nums[i]) is not None:
                return [hashset.get(target-nums[i]), i]
            hashset[nums[i]] = i

def main():
    s = Solution()
    a = [2, 4, 4, 9]
    b = s.twoSumHash(nums = a, target = 6)
    for num in b:
       print(num)

main()
