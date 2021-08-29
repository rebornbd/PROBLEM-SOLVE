
def removeElement(nums, val):
    k = 0
    for i in range(0, len(nums)):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
    return k

nums = [3,2,2,3]
val = 2
res = removeElement(nums, val)

print(res)
for i in range(0, res):
    print(nums[i], end=" ")
