from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        word_length = len(words[0])
        word_count = len(words)
        total_length = word_length * word_count

        word_map = Counter(words)
        result = []

        for i in range(word_length):
            current_map = Counter()
            count = 0
            left = i

            for j in range(i, len(s) - word_length + 1, word_length):
                sub = s[j:j + word_length]
                if sub in word_map:
                    current_map[sub] += 1
                    count += 1
                    while current_map[sub] > word_map[sub]:
                        left_sub = s[left:left + word_length]
                        current_map[left_sub] -= 1
                        count -= 1
                        left += word_length
                    if count == word_count:
                        result.append(left)
                else:
                    current_map.clear()
                    count = 0
                    left = j + word_length

        return result
