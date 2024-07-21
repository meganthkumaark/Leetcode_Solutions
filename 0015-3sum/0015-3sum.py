class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue # Skip duplicates
            target = -nums[i]
            left, right = i + 1, n - 1
            
            while left < right:
                sum = nums[left] + nums[right]
                if sum == target:
                    result.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1 # Skip duplicates
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1 # Skip duplicates
                    left += 1
                    right -= 1
                elif sum < target:
                    left += 1
                else:
                    right -= 1
        
        return result
