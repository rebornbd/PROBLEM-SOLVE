
def searchInsert(nums, target):
    l = 0
    r = len(nums) - 1
    
    while(r >= l):
        m = (l+r) // 2
        
        if nums[m] == target:
            return m
        
        elif nums[m] < target:
            l = m + 1
        else: r = m - 1
    
    return l

nums = [1,3,5,6]
target = 4

res = searchInsert(nums, target)
print(res)
