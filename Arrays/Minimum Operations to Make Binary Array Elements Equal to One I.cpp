https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size(), operations = 0;
    
            for(int i=0;i < n-2;i++){
                if(nums[i] == 0){
                    nums[i] = abs(1 - nums[i]);
                    nums[i+1] = abs(1 - nums[i+1]);
                    nums[i+2] = abs(1 - nums[i+2]);
                    operations++;
                }else continue;
            }
    
            if(nums[n-2] == 0 || nums[n-1] == 0) return -1;
    
            return operations;
        }
    };