class Solution {
public:
    
    bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto it : arr) pq.push({abs(it-x), it});
        vector<int>ans;
        while(k) {
            int t = pq.top().second;
            pq.pop();
            ans.push_back(t);
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
