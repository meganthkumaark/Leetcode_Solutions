class Solution:
    def majorityElement(self, nums):
        count = 0
        majority = None
        
        for num in nums:
            if count == 0:
                majority = num
            count += (1 if num == majority else -1)
        
        return majority