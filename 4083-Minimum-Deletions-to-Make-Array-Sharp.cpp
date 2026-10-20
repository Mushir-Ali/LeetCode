class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int j = i+1;
            while(j<n and nums[i]==nums[j]){
                j++;
            }
            j--;
            ans+=(j-i);
            i=j;
        }
        return ans;
    }
};