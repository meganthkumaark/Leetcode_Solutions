class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trusts_given = [0] * (n + 1)
        trusts_received = [0] * (n + 1)
        
        for a, b in trust:
            trusts_given[a] += 1
            trusts_received[b] += 1
        
        for i in range(1, n + 1):
            if trusts_given[i] == 0 and trusts_received[i] == n - 1:
                return i
        
        return -1