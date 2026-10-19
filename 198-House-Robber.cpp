class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int a = nums[0];
        int b = max(nums[0],nums[1]);
        int n = nums.size();
        for(int i=2;i<n;i++){
            int c = max(nums[i]+a,b);
            a = b;
            b = c;
        }
        return b;
    }
};