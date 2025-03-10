https://leetcode.com/problems/closest-prime-numbers-in-range/

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int>prime(right+1, 1);
            for(long i=2;i <= right;i++){
                if(prime[i] == 0) continue;
                for(long j=i*i;j <= right; j+=i){
                    prime[j] = 0;
                }
            }
    
            vector<int>temp;
    
            for(int i=max(left, 2);i <= right;i++){
                if(prime[i] == 1) temp.push_back(i);
            }
    
            int minVal = 1e9;
    
            int ans1 = -1, ans2 = -1;
    
            for(int i=1;i < temp.size();i++){
                int curDiff = temp[i] - temp[i-1];
                if(curDiff < minVal) {
                    minVal = curDiff;
                    ans2 = temp[i];
                    ans1 = temp[i-1];
                }
            }
    
            return {ans1, ans2};
        }
    };