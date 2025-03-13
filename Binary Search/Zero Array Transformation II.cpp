https://leetcode.com/problems/zero-array-transformation-ii/

class Solution {
    public:
        bool isPossibleToMakeZero(vector<int>& nums, vector<vector<int>>& queries, int mid){
            int n = nums.size();
            vector<int>prefix(n+1, 0);
    
            for(int i=0;i < mid;i++){
                int l = queries[i][0] , r = queries[i][1] , val = queries[i][2];
    
                prefix[l] += val;
                if(r+1 < n)prefix[r+1] -= val;
            }
    
            for(int i=0;i < n;i++){
                if(i > 0) prefix[i] += prefix[i-1];
    
                if(prefix[i] < nums[i])  return false;
            }
    
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = queries.size();
            int low = 0, high = n, ans = 1e9;
    
            while(low <= high){
                int mid = (low+high)/2;
    
                if(isPossibleToMakeZero(nums, queries, mid)){
                    high = mid-1;
                    ans = min(ans, mid);
                }else low = mid+1;
            }
    
            return (ans == 1e9) ? -1 : ans;
        }
    };