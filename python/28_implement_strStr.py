class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        # a string that contains another string => len of it at least equal to another string
 
        for i in range(len(haystack) - len(needle) + 1):  # +1 for the string with one character
            # compare the slice of haystack with needle
            if haystack[i:i + len(needle)] == needle:
                return i

        return -1
