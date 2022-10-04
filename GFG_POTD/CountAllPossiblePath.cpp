class Solution {
  public:
    
    long long mod = 1e9+7;
    int r, c;
    vector<vector<int>>dp;
    long long solve(int i, int j) {
        if(i > r || j > c) return 0;
        if(i == r && j == c) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans += solve(i+1, j);
        ans += solve(i, j+1);
        return dp[i][j] = (ans % mod);
    }
  
    long long int numberOfPaths(int m, int n){
        r = m;
        c = n;
        dp.resize(r+1, vector<int>(c+1, 1));
        dp[r][c] = 1;
        for(int i = r-1; i >= 1; i--) {
            for(int j = c-1; j >= 1; j--) {
                dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % mod;
            }
        }
        return dp[1][1];
    }
};
