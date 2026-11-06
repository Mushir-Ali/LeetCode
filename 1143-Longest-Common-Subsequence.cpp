class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1;
                    if(i+1<n and j+1<m) dp[i][j]+=dp[i+1][j+1];
                }
                else{
                    if(i+1<n) dp[i][j] = max(dp[i][j],dp[i+1][j]);
                    if(j+1<m) dp[i][j] = max(dp[i][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};