class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        set<int>st;
        for(int i=0;i<n;i++) st.insert(i);
        int val = 0;
        int m = meetings.size();
        vector<int>f(n);
        for(int i=0;i<m;i++){
            while(!pq.empty() and pq.top().first<=meetings[i][0]){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty()){
                long long time = pq.top().first;
                int room = pq.top().second;
                pq.pop();
                pq.push({time+(meetings[i][1]-meetings[i][0]),room});
                f[room]++;
                continue;
            }
            int smallest = *st.begin();
            f[smallest]++;
            pq.push({meetings[i][1],smallest});
            st.erase(smallest);
        }
        int maxi = *max_element(f.begin(),f.end());
        for(int i=0;i<n;i++){
            if(f[i]==maxi) return i;
        }
        return 0;
    }
};