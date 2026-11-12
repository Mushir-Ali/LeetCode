class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int finalans = 1;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) ans++;
            else ans = 1;
            finalans = max(ans,finalans);
        }
        ans = 1;
        for(int i=n-1;i>=1;i--){
            if(nums[i]<nums[i-1]) ans++;
            else ans = 1;
            finalans = max(ans,finalans);
        }
        return finalans;
    }
};