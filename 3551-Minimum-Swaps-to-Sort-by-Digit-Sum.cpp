class Solution {
public:
    int f(int num){
        int sum = 0;
        while(num){
            sum = sum+(num%10);
            num/=10;
        }
        return sum;
    }
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            v.push_back({f(nums[i]),nums[i]});
            mp[nums[i]] = i;
        }
        sort(v.begin(),v.end(),cmp);
        int j=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(mp[v[i].second]==j){
                j++;
                continue;
            }
            ans++;
            int val = mp[v[i].second];
            mp[v[i].second] = j;
            mp[nums[j]] = val;
            swap(nums[val],nums[j]);
            j++;
        }
        return ans;
    }
};