https://leetcode.com/problems/count-primes/

TC ~ O(N) + O(Nlog(logN)) + O(N)
SC ~ O(N)


class Solution {
public:
    int countPrimes(int n) {
        vector<int>prime(n, 1);

        for(long i=2;i < sqrt(n);i++){
            if(prime[i] == 1){
                for(long j=i*i;j < n;j+=i){
                    prime[j] = 0;
                }
            }
        }

        int primes = 0;

        for(int i=2;i < n;i++){
            if(prime[i] == 1) primes++;
        }

        return primes;
    }
};