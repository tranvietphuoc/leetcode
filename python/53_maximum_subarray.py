import math


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dynamic programming
        curr_subarray = max_subarray = nums[0]
        for num in nums[1:]:
            curr_subarray = max(num, curr_subarray + num)
            max_subarray = max(max_subarray, curr_subarray)
        return max_subarray
        
#         # divide and conquer
#         def findBest(nums, left, right):
#             if left > right:
#                 return -math.inf
#             mid = (left + right)//2
#             curr = left_sum = right_sum = 0
#             for i in range(mid - 1, left - 1, -1):
#                 curr += nums[i]
#                 left_sum = max(left_sum, curr)
#             curr = 0
#             for i in range(mid + 1, right +1):
#                 curr += nums[i]
#                 right_sum = max(right_sum, curr)
#             combined_sum = nums[mid] + left_sum + right_sum
#             left_half = findBest(nums, left, mid - 1)
#             right_half = findBest(nums, mid + 1, right)
            
#             return max(combined_sum, left_half, right_half)
#         return findBest(nums, 0, len(nums) - 1)
