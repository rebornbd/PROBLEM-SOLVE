
class Solution:
    def myAtoi(self, s: str) -> int:
        MIN = -2147483648
        MAX = 2147483647
        
        res = 0
        whiteSpace = True
        signNumber = True
        isNegative = False
        for i in range(0, len(s)):
            if s[i] == ' ' and whiteSpace:
                continue
            elif (s[i] == '+' or s[i] == '-') and signNumber:
                whiteSpace = False
                signNumber = False
                if s[i] == '-':
                    isNegative = True
            elif (s[i] >= '0' and s[i] <= '9'):
                whiteSpace = False
                signNumber = False
                res = (res*10)+int(s[i])
                if (res > MAX):
                    break
            else:
                break
        
        if (isNegative):
            res *= -1
        
        if (res <= MIN):
            return MIN
        elif (res >= MAX):
            return MAX
        return res


solve = Solution()

s = "        -123 "
res = solve.myAtoi(s)
print(res)
