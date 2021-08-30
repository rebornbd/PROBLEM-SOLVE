class Solution:
    def fourSum(self, nums, target):
        nums.sort()
        
        ans = set()
        numsLen = len(nums)
        for i in range(0, numsLen-3):
            for j in range(i+1, numsLen-2):
                low = j + 1
                high = numsLen - 1
                
                while (high > low):
                    sum = nums[i] + nums[j] + nums[low] + nums[high]
                    
                    if (sum == target):
                        l = [nums[i], nums[j], nums[low], nums[high]]
                        l.sort()
                        t = tuple(l)
                        ans.add(t)
                        
                        while(high > low and (nums[low] == nums[low+1])): low += 1
                        while(high > low and (nums[high] == nums[high-1])): high -= 1
                        low += 1
                        high -= 1
                    
                    elif sum < target: low += 1
                    else: high -= 1
        res = []
        for s in ans:
            sol = list(s)
            res.append(sol)
        return res

solve = Solution()

nums = [2,2,2,2,2]
target = 8

nums = [-3,-1,0,2,4,5, -10]
target = 2

res = solve.fourSum(nums, target)
print(res)
