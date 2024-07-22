class Solution:
    def validStrings(self, num):
        if num == 0:
            return []
        if num == 1:
            return ["0", "1"]
        
        all_strings = [bin(i)[2:].zfill(num) for i in range(2**num)]
        
        valid_strings = [s for s in all_strings if "00" not in s]
        
        return valid_strings