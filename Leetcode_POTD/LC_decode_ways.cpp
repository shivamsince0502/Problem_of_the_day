// only reccursion

class Solution {
public:

    int solve(int idx, string s){
        if(idx >= s.length()) return 1;
        if(s[idx] == '0') return 0;
        int num = s[idx]-'0', nNum = -1;
        if(idx+1 < s.length()) nNum = num*10+(s[idx+1]-'0');
        int t1 = solve(idx+1, s);
        if(nNum <= 26 && nNum > 0) t1 += solve(idx+2, s);
        // cout<<s[idx]<<" "<<num<<" "<<nNum<<endl;
        return t1;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        return solve(0, s);
    }
};


// with memoization
class Solution {
public:
    vector<int>dp;
    int solve(int idx, string s){
        if(idx >= s.length()) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int num = s[idx]-'0', nNum = -1;
        if(idx+1 < s.length()) nNum = num*10+(s[idx+1]-'0');
        int t1 = solve(idx+1, s);
        if(nNum <= 26 && nNum > 0) t1 += solve(idx+2, s);
        // cout<<s[idx]<<" "<<num<<" "<<nNum<<endl;
        return dp[idx] = t1;
    }
    int numDecodings(string s) {
        dp.resize(s.length()+1, -1);
        if(s[0] == '0') return 0;
        return solve(0, s);
    }
};

// with tabulation
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[n] = 1;
        for(int i = n-1; i >= 0; --i) {
            if(s[i] != '0') {
                dp[i] += dp[i+1];
            }
            if(i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};

// reducing space complexity
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp1 = 1, dp2 = 0, dp = 0;
        for(int i = n-1; i >= 0; --i) {
            if(s[i] != '0') 
                dp += dp1;
            
            if(i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};
