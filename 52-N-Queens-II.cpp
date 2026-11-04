class Solution {
public:
    vector<vector<int>>grid;
    bool safe(int r,int c,int n){
        int i = r;
        while(i--){
            if(grid[i][c]==1) return false;
        }
        int j = c;
        i = r;
        while(i>=0 and j>=0){
            if(grid[i][j]==1) return false;
            i--;
            j--;
        }
        i = r;
        j = c;
        while(i>=0 and j<n){
            if(grid[i][j]==1) return false;
            i--;
            j++;
        }
        return true;
    }
    int solve(int r,int n){
        if(r==n){
            return 1;
        }
        int ans = 0;
        for(int c=0;c<n;c++){
            if(safe(r,c,n)){
                grid[r][c] = 1;
                ans+=solve(r+1,n);
                grid[r][c] = 0;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        grid.resize(n,vector<int>(n,0));
        return solve(0,n);
    }
};