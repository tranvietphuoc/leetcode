class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        start, end = 0, len(nums) - 1
        while start < end:
            if nums[start] == nums[start + 1]:
                nums.pop(start)
                start -= 1
                end -= 1
            start += 1
