class Solution:
    def threeSumClosest(self, nums, target):
        nums.sort()
        
        numsLen = len(nums)
        res = float('inf')
        for i in range(0, numsLen-2):
            if i > 0 and (nums[i] == nums[i-1]): continue
            
            low = i + 1
            high = numsLen - 1
            while high > low:
                sum = nums[i] + nums[low] + nums[high]
                
                if sum == target: return sum
                elif sum < target: low += 1
                else: high -= 1
                
                prevDistance = abs(target - res)
                currDistance = abs(target - sum)
                if (prevDistance > currDistance):
                    res = sum
        return res


solve = Solution()

nums = [-1,2,1,-4]
target = 1

res = solve.threeSumClosest(nums, target)
print(res)
