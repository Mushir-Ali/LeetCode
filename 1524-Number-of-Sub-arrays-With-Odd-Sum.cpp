class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                dp[i+1][0] += 1;
                dp[i+1][0] += dp[i][0];
                dp[i+1][1] += dp[i][1];
            }
            else{
                dp[i+1][1] += 1;
                dp[i+1][1] += dp[i][0];
                dp[i+1][0] += dp[i][1];
            }
        }
        int ans = 0;
        for(int i=0;i<=n;i++){
            ans = (ans + dp[i][1])%1000000007;
        }
        return ans;
    }
};