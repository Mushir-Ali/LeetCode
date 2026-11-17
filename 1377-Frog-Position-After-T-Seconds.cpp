class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        queue<pair<int,pair<double,int>>>q;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n+1);
        q.push({1,{1.0,0}});
        vis[1] = 1;
        while(!q.empty()){
            int node = q.front().first;
            double prob = q.front().second.first;
            int time = q.front().second.second;
            q.pop();
            int c = 0;
            for(int i=0;i<adj[node].size();i++){
                if(!vis[adj[node][i]]){
                    c++;
                }
            }
            if(time>=t){
                if(node==target) return prob;
                continue;
            }
            if(node == target){
                if(c == 0) return prob;
                return 0.0;
            }
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push({i,{prob*(1.0/c),time+1}});
                }
            }
        }
        return double(0);
    }
};