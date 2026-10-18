class Solution {
public:
    int f(int i,string&s, int n,vector<int>&dp){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        // choices
        // 2 choices
        // first one -> take only one element
        int ans = 0;
        if(s[i]!='0'){
            ans += f(i+1,s,n,dp);
        }
        // second one -> take only two elements together (combined)
        if(i+1<n and s[i]>'0' and ((s[i]-'0')*10+(s[i+1]-'0'))<=26){
            ans += f(i+2,s,n,dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return f(0,s,s.size(),dp);
    }
};