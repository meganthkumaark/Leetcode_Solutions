class Solution:
    def singleNumber(self, nums):
        # XOR all the numbers to get the XOR of the two unique numbers
        xor = 0
        for num in nums:
            xor ^= num

        # Find a set bit in the xor (rightmost set bit)
        diff = xor & (-xor)

        # Initialize the two unique numbers
        num1, num2 = 0, 0
        for num in nums:
            if num & diff:
                num1 ^= num
            else:
                num2 ^= num

        return [num1, num2]
