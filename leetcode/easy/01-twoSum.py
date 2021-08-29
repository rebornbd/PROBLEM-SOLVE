
def twoSum(nums, target):
    hasNum = {}
    for i in range(len(nums)):
        nextNumber = target - nums[i]
        
        if nextNumber in hasNum:
            return [hasNum[nextNumber], i]
        hasNum[nums[i]] = i
    
    return []

nums = [2, 7, 11, 15]
target = 18

res = twoSum(nums, target)
print(res)
