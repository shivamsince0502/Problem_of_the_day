long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(int i = 0; i < n; i++) 
            minHeap.push(arr[i]);
        long long cost = 0;
        while(minHeap.size() >= 2) {
            long long f = minHeap.top();
            minHeap.pop();
            long long s = minHeap.top();
            minHeap.pop();
            long long sum = f+s;
            cost += (sum);
            minHeap.push(sum);
        }
        return cost;
