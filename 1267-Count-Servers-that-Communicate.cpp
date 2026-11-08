class DSU {
private:
    vector<int> parent,size;
public:
    DSU(int n)
    {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int getPar(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node] = getPar(parent[node]);
    }
    void unite(int u, int v)
    {
        int pu = getPar(u);
        int pv = getPar(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv]) {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
    int siz(int n) {
        int p = getPar(n);
        return size[p];
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>>v;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) v.push_back({i,j});
            }
        }
        DSU dsu(v.size());
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i][0] == v[j][0] || v[i][1] == v[j][1]) {
                    dsu.unite(i, j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<v.size();i++){
            if(dsu.getPar(i)==i && dsu.siz(i)>1){
                ans += dsu.siz(i);
            }
        }
        return ans;
    }
};