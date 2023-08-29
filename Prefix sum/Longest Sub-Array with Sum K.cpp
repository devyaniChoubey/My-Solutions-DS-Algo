https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int ,int>mp;
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i=0;i < N;i++){
            if(A[i] == K) maxLen = max(maxLen, 1);
            
            prefixSum += A[i];
            
            if(prefixSum == K) maxLen = max(maxLen, i+1);
            
            if(mp.find(prefixSum - K) != mp.end()) maxLen = max(maxLen, i - mp[prefixSum - K]);
            
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;
            }
            
        }
        
        return maxLen;
    } 

};