class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = min({
                dp[i-1] + costs[i-1] + 1,
                i>=2 ? dp[i-2]+costs[i-1]+4 : (int)1e9,
                i>=3 ? dp[i-3]+costs[i-1]+9 : (int)1e9
            });
        }
        return dp[n];
    }
};