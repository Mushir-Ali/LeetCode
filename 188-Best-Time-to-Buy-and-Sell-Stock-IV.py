class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        n = len(prices)
        dp = [[[-1]*2 for _ in range(k+1)] for _ in range(n+1)]
        def f(i,k,buy):
            if i==n: return 0
            if k==0: return 0
            if dp[i][k][buy]!=-1: return dp[i][k][buy]
            if buy==0:
                # to buy
                dp[i][k][buy] = max(f(i+1,k,buy),-prices[i]+f(i+1,k,1))
            else:
                # to sell
                dp[i][k][buy] = max(f(i+1,k,buy),prices[i]+f(i+1,k-1,0))
            return dp[i][k][buy]
        return f(0,k,0)