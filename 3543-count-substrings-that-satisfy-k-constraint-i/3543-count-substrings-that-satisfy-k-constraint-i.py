class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        nnn = len(s)
        counter = 0
        
        for i in range(nnn):
            zero_counter = 0
            one_counter = 0
            for j in range(i, nnn):
                if s[j] == '0':
                    zero_counter += 1
                else:
                    one_counter += 1
                
                if zero_counter <= k or one_counter <= k:
                    counter += 1
                else:
                    break 
        
        return counter
