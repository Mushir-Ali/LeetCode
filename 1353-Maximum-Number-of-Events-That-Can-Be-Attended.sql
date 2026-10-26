class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        int day = events[0][0];
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        int ans = 0;
        while(!pq.empty() or i<n){
            while(i<n and events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty() and day<=pq.top()){
                ans++;
                pq.pop();
            }
            day++;
            while(!pq.empty() and pq.top()<day){
                pq.pop();
            }
        }
        return ans;
    }
};