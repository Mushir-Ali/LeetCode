class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    long long bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<long long, long long>> q;
        q.push({i, j});
        vis[i][j] = 1;
        long long sum = grid[i][j];
    
        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
    
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
    
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
    
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    !vis[nx][ny] && grid[nx][ny] > 0) {
                    vis[nx][ny] = 1;
                    sum += grid[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
    
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    long long islandSum = bfs(i, j,grid,vis);
                    if (islandSum % k == 0) {
                        cnt++;
                    }
                }
            }
        }
    
        return cnt;
    }
};