class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        count_of_val = 0
        for element in nums:
            if element == val:
                count_of_val += 1
        
        for _ in range(count_of_val):
            nums.remove(val)
