from typing import List

class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        str_nums = [str(num) for num in nums]
        num_length = len(str_nums[0])
        total_nums = len(nums)
        total_diff_sum = 0
        
        for i in range(num_length):
            digit_count = [0] * 10
            for num_str in str_nums:
                digit = int(num_str[i])
                digit_count[digit] += 1
            
            diff_sum_at_position = 0
            for digit in range(10):
                if digit_count[digit] > 0:
                    diff_sum_at_position += digit_count[digit] * (total_nums - digit_count[digit])
            
            total_diff_sum += diff_sum_at_position
        
        total_diff_sum //= 2
        
        return total_diff_sum


