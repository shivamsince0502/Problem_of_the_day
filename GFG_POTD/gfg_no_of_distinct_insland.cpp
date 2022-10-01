class Solution {
  public:
    vector<vector<int>> vis;
    int n, m;
    
    void dfs(int i, int j, int px, int py, vector<pair<int, int>>& vec, vector<vector<int>>& grid) {
        vis[i][j] = true;
        vec.push_back({px-i, py-j});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if((nx >= 0 && ny >= 0 && nx < n && ny < m) && vis[nx][ny] == 0 && grid[nx][ny] == 1) {
                dfs(nx, ny, px, py, vec, grid);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>>st;
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, i, j, vec, grid);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
