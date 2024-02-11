class Solution(object):
     def cherryPickup(self, grid):
        n = len(grid)
        dp = [[[-1 for _ in range(50)] for _ in range(50)] for _ in range(50)]

        def rec(i, j, k):
            q = i + j - k
            if i >= n or j >= n or k >= n or q >= n:
                return -1e8
            if grid[i][j] == -1 or grid[k][q] == -1:
                return -1e8
            if k == n - 1 and q == n - 1:
                return grid[i][j]

            if dp[i][j][k] != -1:
                return dp[i][j][k]

            ans = -1e8
            value = grid[i][j]
            if i != k or j != q:
                value += grid[k][q]

            ans = max(
                ans,
                value + rec(i + 1, j, k + 1),
                value + rec(i, j + 1, k + 1),
                value + rec(i, j + 1, k),
                value + rec(i + 1, j, k)
            )
            dp[i][j][k] = ans
            return ans

        if n == 1:
            return max(grid[0][0], 0)

        result = max(rec(0, 0, 0), 0)
        return result

        