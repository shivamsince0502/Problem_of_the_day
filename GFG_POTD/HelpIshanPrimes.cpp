bool isPrime(int n)
	    {
	        if(n<=1)
	        return false;
	        for(int i=2;i<=n/2;i++)
	        {
	            if(n%i==0)
	            return false;
	        }
	        return true;
	    }
		int NthTerm(int N){
		    // Code here
		    int cnt = 0;
		    int i = 1;
		    if(isPrime(N))
		    return 0;
		    while((N-i)>=0)
		    {
		        if(isPrime(N-i) or isPrime(N+i))
		        return i;
		        else
		        i++;
		    }
		    return 0;
		}
