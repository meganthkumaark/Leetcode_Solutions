class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        flip = [0] * n
        flips = 0
        result = 0
        
        for i in range(n):
            if i >= k:
                flips ^= flip[i - k]
            if nums[i] == flips % 2:
                if i + k > n:
                    return -1
                flip[i] = 1
                flips ^= 1
                result += 1
        
        return result
