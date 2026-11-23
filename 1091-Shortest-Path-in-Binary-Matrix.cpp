class Solution {
public:
    int x[8]={0,1,0,-1,1,-1,1,-1};
    int y[8]={1,0,-1,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int> >dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        if(grid[0][0]==0){
            pq.push({1,{0,0}});
            dist[0][0]=1;
        }
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int nr = x[i];
                int nc = y[i];
                if(r+nr>=0 and r+nr<n and c+nc>=0 and c+nc<n and grid[r+nr][c+nc]==0){
                    if(d+1<dist[r+nr][c+nc]){
                        dist[r+nr][c+nc] = d+1;
                        pq.push({dist[r+nr][c+nc],{r+nr,c+nc}});
                    }
                }
            }
        }
        return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1];
    }
};