class Solution {
  public:
    
    int fillingBucket(int n) {
        int mod = 1e8;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) 
            dp[i] = (dp[i-1] + dp[i-2])% mod;
        
        return dp[n];
    }
};
