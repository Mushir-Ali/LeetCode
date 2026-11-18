class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        dp = {}
        k = 2
        def f(i,k,buy):
            if i==n: return 0
            if k==0: return 0
            if (i,k,buy) in dp: return dp[(i,k,buy)]
            if buy==0:
                # to buy
                dp[(i,k,buy)] = max(f(i+1,k,buy),-prices[i]+f(i+1,k,1))
            else:
                # to sell
                dp[(i,k,buy)] = max(f(i+1,k,buy),prices[i]+f(i+1,k-1,0))
            return dp[(i,k,buy)]
        return f(0,k,0)