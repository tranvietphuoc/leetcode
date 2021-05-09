class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        # find the longest descending subarray from end to start
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1
        if i == -1:
            nums.reverse()
            return
        j = len(nums) - 1
        while j >= 0 and nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]  # swap
        nums[i + 1:] = sorted(nums[i + 1:])  # sorted ascending from i
