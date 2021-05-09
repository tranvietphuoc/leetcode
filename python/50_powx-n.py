class Solution:
    def myPow(self, x: float, n: int) -> float:
        power = 1
        if n < 0:
            x = 1 / x
            n = abs(n)
        while n:
            if n & 1:  # check if n is odd
                power *= x
            x *= x
            n >>= 1  # n divide to 2
            
        return power
