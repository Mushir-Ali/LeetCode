class Solution {
public:
vector<vector<vector<int>>>dp;
    bool f(int i,int j,int k,string&s1,string&s2,string&s3,int n,int m,int o){
        if(i==n and j==m){
            if(k==o) return true;
        }
        if(k==o) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool ans = false;
        if(i<n and k<o and s1[i]==s3[k]){
            ans = ans | f(i+1,j,k+1,s1,s2,s3,n,m,o);
        }
        if(j<m and k<o and s2[j]==s3[k]){
            ans = ans | f(i,j+1,k+1,s1,s2,s3,n,m,o);
        }
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()<s3.size() or s1.size()+s2.size()>s3.size()) return false;
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(o+1,-1)));
        return f(0,0,0,s1,s2,s3,s1.size(),s2.size(),s3.size());
    }
};