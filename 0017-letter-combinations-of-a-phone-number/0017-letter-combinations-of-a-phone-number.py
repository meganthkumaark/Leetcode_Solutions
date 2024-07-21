from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        phone = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }
        
        def backtrack(combination, next_digits):
            if not next_digits:
                output.append(combination)
            else:
                for letter in phone[next_digits[0]]:
                    backtrack(combination + letter, next_digits[1:])
        
        output = []
        backtrack("", digits)
        return output
