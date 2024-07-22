class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n <= 1:
            return
        
        # Step 1: Find the first decreasing element from the end
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        
        if i >= 0:
            # Step 2: Find the element just larger than nums[i] to the right of nums[i]
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            # Swap the found elements
            nums[i], nums[j] = nums[j], nums[i]
        
        # Step 3: Reverse the elements to the right of i
        nums[i + 1:] = reversed(nums[i + 1:])
