class Solution:
    def addBinary(self, a: str, b: str) -> str:
        x = y = c = 0
        for i in a[::-1]:
            if i == '1':
                x += 2**c
            c += 1
        c = 0
        for j in b[::-1]:
            if j == '1':
                y += 2**c
            c += 1
        return bin(x + y)[2:]
