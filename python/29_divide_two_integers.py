import math
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if math.trunc(dividend / divisor) >= 2**31 - 1:
            return 2**31 - 1
        elif math.trunc(dividend / divisor) <= -2**31:
            return -2**31
        else:
            return math.trunc(dividend / divisor)
