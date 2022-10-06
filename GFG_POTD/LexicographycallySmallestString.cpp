class Solution {
  public:
    string lexicographicallySmallest(string str, int k) {
        // code here
        string s = str;
        int n = s.length();
        if(n & (n-1)) k *= 2;
        else k /= 2;
        if(k >= n) return "-1";
        
        stack<char> st;
        st.push('Z');
        int req = n-k;
        for(int i = 0; i < n;i++) {
            char ch = str[i];
            while(st.size() > 1 && k && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(st.size() > 1 && k) {
            st.pop();
            k--;
        }
        string res = "";
        int t = 0;
        while(st.size() > 1) {
            res.push_back(st.top());
            st.pop();
        }
        if(res == "") return "-1";
        reverse(res.begin(), res.end());
        return res;
    }
};
