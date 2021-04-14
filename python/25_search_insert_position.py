class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int: 
        if target not in nums:
            if target > nums[len(nums) - 1]:
                return len(nums)
            elif target < nums[0]:
                return 0
            else:
                for i, e in enumerate(nums):
                    if e > target:
                        return i
        return nums.index(target)
