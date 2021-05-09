class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.strip().split(" ")
        if s == " ":
            return 0
        else:
            return len(words[-1])
