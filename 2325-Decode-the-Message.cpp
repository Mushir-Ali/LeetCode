class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char>v(26,'/');
        int cnt = 0;
        for(int i=0;i<key.size();i++){
            if(key[i]==' ') continue;
            if(v[key[i]-'a']=='/'){
                v[key[i]-'a'] = (char)('a'+cnt);
                cnt++;
            }
        }
        for(int i=0;i<26;i++) cout<<v[i]<<" ";
        string ans = "";
        for(int i=0;i<message.size();i++){
            if(message[i]==' ') ans.push_back(' ');
            else ans.push_back(v[message[i]-'a']);
        }
        return ans;
    }
};