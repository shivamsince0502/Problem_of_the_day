class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int mini = INT_MAX, maxi = INT_MIN;
    	for(int i = 0; i < N; i++) {
    	    mini = min(mini, A[i]);
    	    maxi = max(maxi, A[i]);
    	}
    	return (mini + maxi);
    }

};
