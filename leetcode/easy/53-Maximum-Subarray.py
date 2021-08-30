import math

def maxSubArray(nums):
    ans = -(math.inf)
    a = 0
    for num in nums:
        a += num
        ans = max(ans, a)
        a = max(a, 0)
    return ans

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
maxSum = maxSubArray(nums)
print(maxSum)
