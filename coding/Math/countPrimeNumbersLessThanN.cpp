// https://leetcode.com/problems/count-primes/submissions/1642577084/

// Time : O(nlog(logn))
// Space : O(n)


// sive of erastosthenes 
    void helper(vector<int> &isPrime, int n){
        for(int i = 2; i*i < n; i++){
            if(isPrime[i] == 1){
                for(int j = i*i ; j<n;j += i){
                    isPrime[j] = 0;
                }
            }
        }
    }
    int countPrimes(int n) {
        vector<int>isPrime(n+1, 1);

        helper(isPrime, n);

        int count = 0;

        for(int i = 2; i<n;i++){
            if(isPrime[i] == 1){
                count++;
            }
        }

        return count;
    }