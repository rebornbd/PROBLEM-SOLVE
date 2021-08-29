
def removeDuplicates(nums):
    nums[:] = sorted(set(nums))
    return (len(nums))

nums = [0,0,1,1,1,2,2,3,3,4]
res = removeDuplicates(nums)
print(nums)
print(res)
