
def plusOne(digits):
    number = 0
    digitLen = len(digits)
    for i in range(0, digitLen):
        number += (10 ** (digitLen - i - 1))*digits[i]
    number += 1
        
    res = []
    while (number > 0):
        r = number % 10
        number //= 10
        res.append(r)
    res.reverse()
    return res

digits = [9, 9, 9]
res = plusOne(digits)
print(res)
