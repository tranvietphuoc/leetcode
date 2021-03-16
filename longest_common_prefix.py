class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = ""
        if not len(strs):  # check input list
            return common

        for i, char in enumerate(strs[0]):
            for nstr in strs[1:]:
                if len(nstr) - 1 < i or nstr[i] != char:
                    return common

            common += char
        return common
