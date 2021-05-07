class Solution:
    # def permute(self, nums: List[int]) -> List[List[int]]:
    #     def backtrack(arr, step):
    #         if step == len(nums):
    #             res.append(arr)
    #             return

    #         for i, e in enumerate(nums):
    #             if not flag[i]:
    #                 flag[i] = True
    #                 backtrack(arr + [e], step + 1)
    #                 flag[i] = False

    #     res, flag = [], [False] * len(nums)
    #     backtrack([], 0)
    #     return res

    # more optimization
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
            
        def backtrack(pos):
            if pos == len(nums):
                res.append(nums[:])
                return

            for i in range(pos, len(nums)):
                nums[pos], nums[i] = nums[i], nums[pos]  # swap permutations
                backtrack(pos + 1)
                nums[pos], nums[i] = nums[i], nums[pos]  # swap to previous
            
        backtrack(0)
        return res


