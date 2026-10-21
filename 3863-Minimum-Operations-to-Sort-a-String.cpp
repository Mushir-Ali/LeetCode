class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(),t.end());
        if(n==2){
            if(t!=s) return -1;
        }
        if(t==s) return 0;
        // reverse(t.begin(),t.end());
        // if(s==t) return 3;
        char maxi1 = s[n-1];
        char maxi2 = s[0];
        for(int i=n-2;i>=1;i--){
            maxi1 = min(s[i],maxi1);
        }
        for(int i=0;i<n-1;i++){
            maxi2 = max(s[i],maxi2);
        }
        if(s[0]<=maxi1 || s[n-1]>=maxi2) return 1;
        for (int i=1;i<n-1;i++){
            if(s[i]==maxi1 || s[i]==maxi2){
                return 2;
            }
        }        
        return 3;
    }
};