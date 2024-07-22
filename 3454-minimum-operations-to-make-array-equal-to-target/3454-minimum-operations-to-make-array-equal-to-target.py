class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        difft = [target[i] - nums[i] for i in range(len(nums))]       
        total_operation = 0
        current_segment_difft = 0       
        for i in range(len(difft)):
            if i == 0 or (difft[i - 1] > 0 and difft[i] > 0) or (difft[i - 1] < 0 and difft[i] < 0):
                additional_operation = abs(difft[i]) - abs(current_segment_difft)
                if additional_operation > 0:
                    total_operation += additional_operation
                current_segment_difft = difft[i]
            else:  
                total_operation += abs(difft[i])
                current_segment_difft = difft[i]        
        return total_operation