class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(26,0);
        vector<int>v;
        for(int i=0;i<p.size();i++) freq[p[i]-'a']--;
        int n = s.size();
        int m = p.size();
        int i = 0;
        for(int j=0;j<n;j++){
            freq[s[j]-'a']++;
            while(j-i+1>m){
                freq[s[i]-'a']--;
                i++;
            }
            bool f = true;
            for(int k=0;k<26;k++){
                if(freq[k]!=0) f = false;
            }
            if(f and j-i+1==m) v.push_back(i);
        }
        return v;
    }
};