// brute force one
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<pair<int, int>> hx;
        for(int i = 0; i < b.size(); i++) {
            hx.push_back({b[i][0], -b[i][2]});
            hx.push_back({b[i][1], b[i][2]});
        }
        sort(hx.begin(), hx.end());
        vector<vector<int>> ans;
        int curr = 0;
        priority_queue<int> pq;
        pq.push(0); 
        for(auto it : hx) {
            if(it.second < 0) 
                pq.push(abs(it.second));
            else {
                vector<int> temp;
                while(pq.top() != 0) {
                    if(pq.top() == it.second){
                        pq.pop();
                        break;
                    }else {
                        temp.push_back(pq.top());
                        pq.pop();
                    }
                }
                int i = temp.size();
                while(i > 0 ){
                    pq.push(temp[i-1]);
                    i--;
                }
            }
            if(curr != pq.top()) {
                curr = pq.top();
                
                ans.push_back({it.first, curr});
            }
        }
        return ans;
    }
};



// optimized one
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<pair<int, int>> hx;
        
        for(int i = 0; i < b.size(); i++) {
            hx.push_back({b[i][0], -b[i][2]});
            hx.push_back({b[i][1], b[i][2]});
        }
        
        sort(hx.begin(), hx.end());
        
        vector<vector<int>> ans;
        
        int curr = 0, prev = 0;
        
        multiset<int>m;
        
        m.insert(0); 
        
        for(auto it : hx) {
            
            if(it.second < 0) {
                
                m.insert(abs(it.second));
            }
            else {
                
                m.erase(m.find(it.second));
                
            }
            curr = *m.rbegin();
            
            if(prev != curr) {
                
                ans.push_back({it.first, curr});
                
                prev = curr;
            }
            
        }
        
        return ans;
    }
};
