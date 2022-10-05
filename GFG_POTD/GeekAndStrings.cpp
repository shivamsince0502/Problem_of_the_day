class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        unordered_map<string, int> map;
        for(int i = 0; i < N; i++) {
            string s = "";
            for(int j = 0; j < li[i].length(); j++) {
                s += li[i][j];
                map[s]++;
            }
        }
        vector<int> sum;
        for(int i = 0; i < Q; i++) {
            int t = map[query[i]];
            sum.push_back(t);
        }
        return sum;
    }
};
