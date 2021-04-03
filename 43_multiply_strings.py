class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        # convert two strings to two numbers

        factor = 10 ** (len(num1)-1)
        one, two = 0, 0

        for i in num1:
            one += factor * (ord(i) - ord('0'))
            factor = factor // 10

        factor = 10 ** (len(num2) - 1)
        for i in num2:
            two += factor * (ord(i) - ord('0'))
            factor = factor // 10

        return str(one*two)
