class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        def count(red, blue):
            i = 1
            while red >= i:
                red -= i
                blue, red = red, blue
                i += 1
            return i - 1    
        
        return max(count(red, blue), count(blue, red))

            
        