class Solution:
    def canMakeArithmeticProgression(self, arr):
        ans = arr
        ans.sort()
        delta = ans[1] - ans[0]
        for i in range(1, len(arr) - 1):
            if ans[i+1] - ans[i] != delta:
                return False
        return True

    def canMakeArithmeticProgression_2(self, arr):
        maxNum = max(arr)
        minNum = min(arr)
        if maxNum == minNum:
            return True
        n = len(arr)
        if (maxNum - minNum) % (n - 1) != 0:
            return False
        else:
            delta = (maxNum - minNum) / (n - 1)
            ansDict = {minNum+delta*i: 0 for i in range(n)}
            for num in arr:
                if ansDict.get(num) is None:
                    return False
                else:
                    ansDict.pop(num)
        return True
