class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9 + 7
        dp = [[[0] * n for _ in range(m)] for _ in range(maxMove + 1)]
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        for move in range(1, maxMove + 1):
            for row in range(m):
                for col in range(n):
                    for dr, dc in directions:
                        nr, nc = row + dr, col + dc
                        if nr < 0 or nr >= m or nc < 0 or nc >= n:
                            dp[move][row][col] += 1
                        else:
                            dp[move][row][col] = (dp[move][row][col] + dp[move - 1][nr][nc]) % MOD
        
        return dp[maxMove][startRow][startColumn]