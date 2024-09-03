https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

Longest Sub-Array with Sum K

class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        
        unordered_map<int,int>mp;
        int sum = 0, len = 0;
        
        for(int i=0;i < n;i++){
            sum += a[i];
            if(sum == k) len = max(len , i+1);
            if(mp.find(sum - k) != mp.end()) {
                len = max(len , i - mp[sum-k]);
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        
        return len;
    } 

};