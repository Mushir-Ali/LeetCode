class Solution {
public:
    bool checkString(string s) {
        bool f = false;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='b') f = true;
            else if(f==true) return false;
        }
        return true;
    }
};