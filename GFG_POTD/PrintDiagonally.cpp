class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> arr)
	{
	    vector<vector<bool>>vis(n, vector<bool>(n, false));
	    vector<int> ans;
		for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++) {
	            int x = i, y = j;
	            while(x < n && y >= 0 && !vis[x][y]){
	                ans.push_back(arr[x][y]);
	                vis[x][y] = true;
	                x++;
	                y--;
	            }
		    }
		}
		return ans;  
	}

};
