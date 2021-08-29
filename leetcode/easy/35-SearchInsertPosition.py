
def searchInsert(nums, target):
    l = 0
    r = len(nums) - 1
    m = 0
    
    if len(nums) == 0:
        return 0
    
    while True:
        m = (l+r) // 2
        
        if nums[m] == target:
            return m
        
        elif nums[m] < target:
            l = m + 1
        else: r = m - 1
        
        if not r >= l:
            if nums[m] < target:
                return m + 1
            else:
                return m

nums = [1,3,5,6]
target = 0

res = searchInsert(nums, target)
print(res)
