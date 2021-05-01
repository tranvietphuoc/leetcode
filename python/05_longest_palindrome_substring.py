class Solution:
    def checkPalindrome(self, s):
        return s == s[::-1]
    
    def longestPalindrome(self, s):
        low = 0
        high = 0
        length = len(s)
        start = 0
        max_length = 1
        
        for i in range(1, length):
             # even palindrome, eg: "abba"
            low = i - 1
            high = i
            while low >= 0 and high < length and s[low] == s[high]:
                if high - low + 1 > max_length:
                    start = low
                    max_length = high - low + 1
    
                low -= 1
                high += 1
            
            # odd palindrome, eg: "aba"
            low = i - 1
            high = i + 1
            
            while low >= 0 and high < length and s[low] == s[high]:
                if high - low + 1 > max_length:
                    start = low
                    max_length = high - low + 1
    
                low -= 1
                high += 1
        if start == 0 and max_length == 0:
            return s[0]
        return s[start:start + max_length]
        
                
    
#     def longestPalindrome(self, s: str) -> str:
#         if s == "":
#             return ""
#         elif len(s) == 1:
#             return s
#         # elif len(s) == 2:
#         #     if s[0] == s[1]:
#         #         return s
#         #     else: return s[0]
            
#         sub_strings = {}
#         for i, sub in enumerate(s, 1):
#             for char in s[i:]:
#                 sub += char
#                 # print(sub)
#                 if self.checkPalindrome(sub):
#                     sub_strings.update({len(sub): sub})
#                     # break
#         print(sub_strings)
#         if list(sub_strings.keys()) == []: return s[0]
#         else: return sub_strings[max(list(sub_strings.keys()))]
                    
