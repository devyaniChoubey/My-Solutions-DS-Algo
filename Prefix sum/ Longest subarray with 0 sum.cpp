https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        unordered_map<int ,int>mp;
        int maxLength = 0;
        int prefixSum = 0;
        
        
        for(int i=0;i < n;i++){
            if(A[i] == 0) maxLength = max(maxLength, 1);
            
            prefixSum += A[i];
            
            if(prefixSum == 0) maxLength = max(maxLength, i+1);
            
            if(mp.find(prefixSum) != mp.end()){
                maxLength = max(maxLength, i - mp[prefixSum]);
            }else{
                mp[prefixSum] = i;
            }
        }
        
        return maxLength;
        
    }
};