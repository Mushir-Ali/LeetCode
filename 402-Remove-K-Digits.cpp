class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        stack<char>st;
        int n = num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()>num[i] and k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() and k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        while(s.size()>0 and s.back()=='0'){
            s.pop_back();
        }
        if(s.size()==0) return "0";
        reverse(s.begin(),s.end());
        return s;
    }
};