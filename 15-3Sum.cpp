class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k])==0){
                    vector<int>v={nums[i],nums[j],nums[k]};
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j>i+1 and j<k and nums[j]==nums[j-1]) j++;
                    while(k<n-1 and k>j and nums[k]==nums[k+1]) k--;
                }
                else if((nums[i]+nums[j]+nums[k])<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};