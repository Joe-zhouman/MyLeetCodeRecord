class Solution:
    def kidsWithCandies(self, candies, extraCandies):
        ans = []
        maxCandy = 0
        for candy in candies:
            if candy > maxCandy:
                maxCandy = candy
        for candy in candies:
            if candy + extraCandies < maxCandy:
                ans.append(False)
            else:
                ans.append(True)
        return ans


candies = [12, 1, 12]
extraCandies = 10
ans = Solution().kidsWithCandies(candies, extraCandies)
for candy in ans:
    print(candy)
