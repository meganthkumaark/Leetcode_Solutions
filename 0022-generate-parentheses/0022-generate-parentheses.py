class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.generate(result, "", 0, 0, n)
        return result
    
    def generate(self, result: List[str], current: str, open: int, close: int, max: int):
        if len(current) == max * 2:
            result.append(current)
            return
        
        if open < max:
            self.generate(result, current + "(", open + 1, close, max)
        
        if close < open:
            self.generate(result, current + ")", open, close + 1, max)
