class Solution {
public:
    int minChanges(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int n = s.size();
        int prev = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            cnt1+=(s[i]=='1');
            cnt0+=(s[i]=='0');
            if((i-prev+1)%2==0){
                ans+=min(cnt0,cnt1);
                prev = i+1;
                cnt0 = 0;
                cnt1 = 0;
            }
        }
        return ans;
    }
};