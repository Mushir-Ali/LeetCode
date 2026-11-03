class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[0]*m for _ in range(n)]

        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                if i==n-1 and j==m-1: dp[i][j] = grid[i][j]
                else:
                    down = 1e9
                    right = 1e9
                    if i+1<n:
                        down = dp[i+1][j]
                    if j+1<m:
                        right = dp[i][j+1]
                    dp[i][j] = grid[i][j] + min(down,right)
        return dp[0][0]
        