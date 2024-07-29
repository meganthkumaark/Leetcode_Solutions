class Solution:
    def frequencySort(self, s):
        char_freq = Counter(s)
        
        sorted_chars = sorted(char_freq.keys(), key=lambda x: char_freq[x], reverse=True)
        
        sorted_string = ''.join(char * char_freq[char] for char in sorted_chars)
        
        return sorted_string