class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        
        def backtrack(pos):
            if pos == len(nums):
                res.append(nums[:])
                return
            
            lookup = set()
            for i in range(pos, len(nums)):
                if nums[i] not in lookup:
                    nums[pos], nums[i] = nums[i], nums[pos]
                    backtrack(pos + 1)
                    nums[pos], nums[i] = nums[i], nums[pos]
                    lookup.add(nums[i])
        
        backtrack(0)
        return res

