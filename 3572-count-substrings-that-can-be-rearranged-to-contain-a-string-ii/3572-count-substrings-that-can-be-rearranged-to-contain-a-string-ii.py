class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        nun = len(word1)
        mum = len(word2)
        if mum > nun:
            return 0
        
        cnt_2 = defaultdict(int)
        cnt_1 = defaultdict(int)
        
        for c in word2:
            cnt_2[c] += 1

        ans = 0
        need = len(cnt_2)  
        formed = 0  
        
        left = 0 
        
        for right in range(nun):
            c = word1[right]
            cnt_1[c] += 1
            
            if c in cnt_2 and cnt_1[c] == cnt_2[c]:
                formed += 1
            
            while formed == need:
                ans += (nun - right)

                left_char = word1[left]
                cnt_1[left_char] -= 1
                if left_char in cnt_2 and cnt_1[left_char] < cnt_2[left_char]:
                    formed -= 1
                left += 1
        
        return ans
