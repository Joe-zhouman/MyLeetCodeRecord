class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        s = (len(nums1) + len(nums2)) % 2
        mi = (len(nums1) + len(nums2) + s) // 2
        i = 0
        j = 0
        k = 0
        while i < len(nums1) and j < len(nums2) and k < mi:
            if nums1[i] < nums2[j]:
                i += 1
                f = 0
            else:
                j += 1
                f = 1
            k += 1
        if k == mi:
            if s != 0:
                if f == 0:
                    return nums1[i-1]
                return nums2[j-1]
            if f == 0:
                if nums1[i] < nums2[j-1]:
                    return (nums1[i-1] + nums1[i])/2
                return (nums1[i-1] + nums2[j-1])/2
            if nums1[i-1] < nums2[j]:
                return (nums2[j-1] + nums1[i - 1])/2
            return (nums1[j-1] + nums1[j])/2
        t = mi - i - j
        if i == len(nums1):
            if s == 0:
                if t == 0:
                    return (nums1[i-1] + nums2[t])/2
                return (nums2[t-1] + nums2[t]) / 2
            return nums2[t-1]
        if s == 0:
            if t == 0:
                return (nums2[j-1] + nums1[t])/2
            return (nums1[t-1] + nums1[t])/2
        return nums1[t-1]


a = [1, 2]
b = [1, 3]
print(Solution().findMedianSortedArrays(a, b))
