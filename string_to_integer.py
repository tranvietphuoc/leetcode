from collections import deque


def valid(char):
    return ord("0") <= ord(char) <= ord("9")


class Solution:
    def myAtoi(self, s: str) -> int:
        d = deque(s)
        # remove blank
        while d and d[0] == " ":
            d.popleft()

        sign = 1
        if d and d[0] == "+":
            d.popleft()
            sign = 1
        elif d and d[0] == "-":
            d.popleft()
            sign = -1

        buffer = ""
        while d and valid(d[0]):
            buffer += d.popleft()

        result = 0
        for i in buffer:
            num = ord(i) - ord("0")
            result = result * 10 + num

        result = result * sign

        if result > 2 ** 31 - 1:
            return 2 ** 31 - 1
        elif result < -(2 ** 31):
            return -(2 ** 31)
        else:
            return result
