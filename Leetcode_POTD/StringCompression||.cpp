

int dp[100][27][100][100];
class Solution {
public:
    string str;
    int solve(int i, int prev, int len, int k) {
        if(k < 0) return 1e9;
        if(i >= str.size()) return 0;
        if(dp[i][prev][len][k] != -1) return dp[i][prev][len][k];
        // if i want to delete current character
        int del = solve(i+1, prev, len, k-1);
        
        // if i want to keep the current char
        int keep = 0;
        // the len is to store the number of occurence of repetetive characters
        if(str[i] - 'a' == prev) {
            // now we have two cases wherether the curr char increses teh length of frecquent to a certain number that will increase the length of resultant string
            if(len == 1 || len == 9 || len == 99) {
                keep += 1;
            }
            keep = keep + solve(i+1, prev, len+1, k);
        }
        else {
            // this is not equal to previous eleement then we will initieate the new length with 1
            keep = 1 + solve(i+1, str[i] - 'a', 1, k);
        }
        
        return dp[i][prev][len][k] = min(del, keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
    }
};
