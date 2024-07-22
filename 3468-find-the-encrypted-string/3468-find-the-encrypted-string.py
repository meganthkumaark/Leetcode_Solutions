class Solution:
    def getEncryptedString(self, s, k):
        num = len(s)
        encrypted_string = ""
        
        for i in range(num):
            # Find the kth character after the current character in a cyclic manner
            new_index = (i + k) % num
            encrypted_string += s[new_index]
        
        return encrypted_string