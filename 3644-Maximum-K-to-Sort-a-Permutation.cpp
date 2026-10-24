class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int val = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==i) continue;
            if(val==-1){
                val = nums[i];
            }
            else{
                val = val & nums[i];
            }
        }
        return (val==-1)?0:val;
    }
};