class Solution {
public:
    
    string getSay(string num) {
        int i = 0, len = num.length();
        string ans = "";
        while(i < len) {
            char curr = num[i];
            int oc = 0;
            while(curr == num[i]) {
                i++;
                oc++;
            }
            string ocr = to_string(oc);
            ans += (ocr + curr);
        }
        return ans;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        if(n == 1) return ans;
        int cnt = 1;
        while(cnt < n) {
            ans = getSay(ans);
            cnt++;
        }
        return ans;
    }
};
