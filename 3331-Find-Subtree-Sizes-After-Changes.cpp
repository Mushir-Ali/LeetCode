class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> sz;
        int components;
        DSU(int n) {
            components = n;
            parent.resize(n);
            sz.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false;
            }
            parent[rootY] = rootX;
            sz[rootX] += sz[rootY];
            components--;
            return true;
        }
        bool connected(int x, int y) {
            return find(x) == find(y);
        }
        int getSize(int x) {
            return sz[find(x)];
        }
        int countComponents() const {
            return components;
        }
    };
    void f(int node, vector<vector<int>>&adj,vector<int>&freq,DSU &dsu, string &s,vector<int>& parent){
        int val = freq[s[node] - 'a'];
        freq[s[node] - 'a'] = node;
        for(auto i:adj[node]){
            f(i,adj,freq,dsu,s,parent);
        }
        freq[s[node] - 'a'] = val;
        if (val != -1) {
            parent[node] = val;
        }
    }
    int dfs(int node, int par, vector<vector<int>>& adj, vector<int>& ans) {
        ans[node] = 1;

        for (auto child : adj[node]) {
            if (child == par) continue;

            ans[node] += dfs(child, node, adj, ans);
        }

        return ans[node];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        DSU dsu(n);
        vector<int>freq(26,-1);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                adj[parent[i]].push_back(i);
            }
        }
        f(0,adj,freq,dsu,s,parent);
        vector<vector<int>> newAdj(n);
        for(int i=1;i<n;i++){
            newAdj[parent[i]].push_back(i);
        }
        vector<int>ans(n);
        dfs(0,-1,newAdj,ans);
        return ans;
    }
};