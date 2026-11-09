class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = 1e9;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return ans;
    }
};