class Solution {
  public:
    

    void getPrimes(int r, vector<bool>& primes, vector<int>& p) {
        for(int i = 2; i*i < r+1; i++) {
            if(primes[i] == true) {
                for(int j = i*i; j < r+1; j += i) {
                    primes[j] = false;
                }
            }
        }
        for(int i = 2; i <= r; i++) {
            if(primes[i]) p.push_back(i);
        }
    }
  
    int sumOfAll(int l, int r){
        // code here
        vector<bool> primes(r+1, true);
        primes[0] = false;
        primes[1] = false;
        vector<int>p;
        getPrimes(r, primes, p);
        int sum = 0;
        for(int i = l; i <= r; i++) {
            if(i == 1) {
                sum++;
                continue;
            }else {
                for(auto it : p){
                    if(primes[it] && (i % it) == 0){
                        sum += it;
                    }
                }
            }
        }
        return sum;
    }
};
