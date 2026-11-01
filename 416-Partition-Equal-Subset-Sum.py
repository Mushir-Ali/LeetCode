
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)

        if total % 2:
            return False

        target = total // 2
        n = len(nums)

        dp = [[-1] * (target + 1) for _ in range(n)]

        def f(i, s):
            if s == 0:
                return True

            if i == n or s < 0:
                return False

            if dp[i][s] != -1:
                return dp[i][s]

            take = f(i + 1, s - nums[i])
            notTake = f(i + 1, s)

            dp[i][s] = take or notTake

            return dp[i][s]

        return f(0, target)
