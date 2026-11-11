class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(26,-1);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']==-1) v[s[i]-'a'] = i;
        }
        int lim = v[s[n-1]-'a'];
        int j = n-1;
        for(int i=0;i<26;i++) cout<<v[i]<<" ";
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(i<lim){
                ans.push_back(j-lim+1);
                j = i;
            }
            lim = min(lim,v[s[i]-'a']);
        }
        ans.push_back(j-lim+1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};