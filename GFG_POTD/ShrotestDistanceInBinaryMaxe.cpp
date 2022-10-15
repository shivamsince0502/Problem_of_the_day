
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> des) {
                         
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if(source == des) return 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {source.first, source.second}});
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!pq.empty()) {
            int dis = pq.top().first;
            pair<int, int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny =  y + dy[k];
                if((nx >= 0 && nx < n && ny >= 0 && ny < m) && grid[nx][ny] == 1) {
                    if(dist[nx][ny] > dis+1) {
                        dist[nx][ny] = dis+1;
                        pq.push({dis+1, {nx, ny}});
                    }
                }
            }
        }
        return dist[des.first][des.second] == 1e9 ? -1 : dist[des.first][des.second];
    }
};
