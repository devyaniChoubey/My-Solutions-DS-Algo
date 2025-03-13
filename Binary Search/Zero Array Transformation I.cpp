https://leetcode.com/problems/zero-array-transformation-i/

class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int>prefix(n, 0);
    
            for(auto &it:queries){
                int l = it[0] , r = it[1];
    
                prefix[l] += 1;
                if(r < n-1)prefix[r+1] -= 1;
            }
    
            for(int i=0;i < n;i++){
                if(i > 0)prefix[i] += prefix[i-1];
    
                if(nums[i] > prefix[i]) return false;
            }
    
            return true;
    
    
        }
    };