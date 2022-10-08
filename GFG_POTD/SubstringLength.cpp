class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        unordered_map<char, int> map;
        int ans = 0;
        for(int i = 0; i < k; i++) 
            map[s[i]]++;
        
        if(map.size() == k-1) ans++;
        int i = 0, j = k;
        while(j < s.length()) {
            if(map[s[i]] > 0 && map[s[i]] - 1 == 0){
                map.erase(s[i]);
            }else map[s[i]]--;
            map[s[j]]++;
            if(map.size() == k-1) ans++;
            i++;
            j++;
        }
        return ans;
    }
};
