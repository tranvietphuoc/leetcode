class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # temp_list = []
        # for i in range(len(nums) - 1):
        #     for j in range(i + 1, len(nums)):
        #         if nums[i] + nums[j] == target:
        #             temp_list.append(i)
        #             temp_list.append(j)
        #             return temp_list

        hash_table = {}
        for i, num in enumerate(nums):
            remaining = target - num
            if remaining not in hash_table:
                hash_table[num] = i
            else:
                return [hash_table[remaining], i]

