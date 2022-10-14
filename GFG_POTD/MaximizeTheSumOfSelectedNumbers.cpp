class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) map[a[i]]++;
        int sum = 0;
        for(int i = n-1; i >= 0; i--) {
            if(map[a[i]] >= 1) {
                sum += a[i];
                map[a[i]]--;
                if(map.find(a[i]-1) != map.end()){
                    map[a[i]-1]--;
                }
            }
        }
        return sum;
    }
};
