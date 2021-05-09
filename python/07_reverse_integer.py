class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            x = (-1)*x
            return (-1)*int(str(x)[::-1]) if (-1)*int(str(x)[::-1]) <= (2**31 - 1) and (-1)*int(str(x)[::-1]) >= (-1)*2**31 else 0

        return int(str(x)[::-1]) if int(str(x)[::-1]) <= (2**31 - 1) and int(str(x)[::-1]) >= (-1)*2**31 else 0
