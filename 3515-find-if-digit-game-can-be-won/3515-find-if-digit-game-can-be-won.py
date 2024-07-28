class Solution:
    def canAliceWin(self, nums):
        sum_less = 0
        sum_greater_or_equal = 0
        
        for num in nums:
            if num < 10:
                sum_less += num
            else:
                sum_greater_or_equal += num
        
        return sum_less != sum_greater_or_equal