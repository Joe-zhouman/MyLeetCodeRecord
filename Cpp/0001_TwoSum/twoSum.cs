using System.Collections.Generic;

namespace twoSumCsharp {
    public static class Solution {
        public static int[] TwoSumDirectly(int[] nums, int target) {
            //688ms 30.9MB
            for (int i = 0; i < nums.Length; i++) {
                for (int j = 0; j < nums.Length; j++) {
                    if (j == i || nums[i] + nums[j] != target)
                        continue;
                    int[] ans = { i, j };
                    return ans;
                }
            }

            return null;
        }

        public static int[] TwoSumHashMap(int[] nums, int target) {
            //284ms 31.3MB
            Dictionary<int, int> numHashtable = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++) {
                int temp = target - nums[i];
                if (numHashtable.ContainsKey(temp)) {
                    int[] ans = {i, numHashtable[temp]};
                    return ans;
                }
                numHashtable[nums[i]] = i;
            }
            return null;
        }
        public static int[] TwoSumTwoThread(int[] nums, int target) {
            //280ms 31MB
            List<int> newList = new List<int>(nums);
            List<int> oldList = new List<int>(nums);
            newList.Sort();
            int hi = nums.Length - 1;
            for (int i = 0; i < hi; i++) {
                int temp = target - newList[i];
                int j = hi;
                while(newList[j] > temp && j > i) {
                    j--;
                }
                if (j == i)
                    return null;
                if (newList[j] == temp) {
                    int[] ans = {oldList.IndexOf(newList[i]),0};
                    ans[1] = newList[i] == temp ? 
                        oldList.IndexOf(temp, ans[0] + 1) : oldList.IndexOf(temp);
                    return ans;
                }
                hi = j;
            }

            return null;
        }
    }
}