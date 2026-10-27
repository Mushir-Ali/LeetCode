class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&v,int n,int k,int i){
        if(n==0 and k==0){
            ans.push_back(v);
            return;
        }
        if(n<0) return;
        for(int j=i;j<=9;j++){
            if(j>n) break;
            v.push_back(j);
            solve(ans,v,n-j,k-1,j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(ans,v,n,k,1);
        return ans;
    }
};