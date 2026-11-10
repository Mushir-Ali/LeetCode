class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<int>st;
        for(int i=0;i<k;i++){
            st.insert(i);
        }
        int n = arrival.size();
        int m = load.size();
        int val = 0;
        vector<int>f(k,0);
        for(int i=0;i<n;i++){
            while(!pq.empty() and pq.top().first<=arrival[i]){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty()) continue;
            auto it = st.lower_bound(i%k);
            if(it==st.end()){
                it = st.begin();
            }
            int server=*it;
            pq.push({arrival[i]+load[i],server});
            st.erase(server);
            f[server]++;
        }
        int ans = 0;
        vector<int>v;
        ans = *max_element(f.begin(),f.end());
        for(int i=0;i<k;i++){
            if(f[i]==ans) v.push_back(i);
        }
        return v;
    }
};