class Solution:
    def isPalindrome(self, x: int) -> bool:
        reversed_x = str(x)[::-1]
        return reversed_x == str(x)
