class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>v = {0,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            v = {x,y};
            q.pop();
            if(grid[x][y]=='L'){
                if(y-1==-1 || vis[x][y-1]) return v;
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
            if(grid[x][y]=='R'){
                if(y+1==m || vis[x][y+1]) return v;
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
            if(grid[x][y]=='U'){
                if(x-1==-1 || vis[x-1][y]) return v;
                vis[x-1][y]=1;
                q.push({x-1,y});
            }
            if(grid[x][y]=='D'){
                if(x+1==n || vis[x+1][y]) return v;
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
        }
        return v;
    }
};