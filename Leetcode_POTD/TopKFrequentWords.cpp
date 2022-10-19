class Solution {
public:
    
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if(a.second > b.second) return true;
        if(a.second == b.second) 
            if(a.first < b.first) return true;
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> map;
        vector<pair<string, int>> ans;
        for(auto str : words) map[str]++;
        for(auto it : map) ans.push_back({it.first, it.second});
        sort(ans.begin(), ans.end(), cmp);
        vector<string> res;
        int i = 0;
        while(i < k) {
            res.push_back(ans[i].first);
            i++;
        }
        return res;
    }
};
