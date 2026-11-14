class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = 1e9;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<=min(n-1,i+r-1);j++){
                sum+=nums[j];
                if(sum>0 and sum<ans and (j-i+1)>=l and (j-i+1)<=r){
                    ans = sum;
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};