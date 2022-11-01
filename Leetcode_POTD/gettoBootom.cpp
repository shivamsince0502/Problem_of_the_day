class Solution {
public:
    int n, m;
    vector<int> ans;
    void solve(int i, int j, int dFor, vector<vector<int>>& grid) {
        if(i >= n) {
            ans[dFor] = j;
            return;
        }
        int curr = grid[i][j];
        if(curr == 1) {
            if(j+1 < m && grid[i][j+1] != -1) solve(i+1, j+1, dFor, grid);
            
        }else {
            if(j-1 >= 0 && grid[i][j-1] != 1) solve(i+1, j-1, dFor, grid);
            
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        ans.resize(m, -1);
        for(int j = 0; j < m; j++) {
            solve(0, j, j, grid);
        }
        return ans;
    }
};
