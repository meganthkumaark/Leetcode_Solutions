class Solution(object):
    def sortJumbled(self, mapping, nums):
        """
        :type mapping: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        def map_number(num):
            mapped_num =''
            for digit in str(num):
                mapped_num += str(mapping[int(digit)])
            return int(mapped_num)
        return sorted(nums, key = map_number)