class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
         if s == "":
            return 0
        
        char_set = set()
        left = 0
        res = 0
        for right, sub in enumerate(s):
            while sub in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(sub)
            res = max(res, right - left + 1)
        return res

        # if s == "":
        #     return 0
        
        # # list all substring of s that not repeating characters
        # sub_list = []
        # for i, sub in enumerate(s, 1):
        #     for char in s[i:]:
        #         if char not in sub:
        #             sub += char
        #         else:
        #             break
        #     sub_list.append(sub)
        # print(sub_list)
        # max_lens = map(len, sub_list)
        # return max(max_lens)
