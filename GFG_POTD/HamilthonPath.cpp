class Solution
{
    public:
    
    vector<bool> vis;
    int nodes;
    bool dfs(int node, int cnt, unordered_map<int, vector<int>>& adj) {
        if(cnt == nodes) return true;
        vis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it] && dfs(it, cnt+1, adj)) {
                return true;
            }
        }
        vis[node] = false;
        return false;
    }
    
    bool check(int n,int m,vector<vector<int>> Edges)
    {
        // code here
        nodes = n;
        unordered_map<int, vector<int>> adj;
        vis.resize(n, false);
        for(auto edge : Edges) {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(i, 1, adj)) return true;
            }
        }   
        return false;
    }
};
 
