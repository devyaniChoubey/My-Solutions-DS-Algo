https://leetcode.com/problems/move-zeroes/description/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZeroFoundAt = 0;
        
        for(int i=0;i < n;i++){
           if(nums[i] != 0)nums[lastNonZeroFoundAt++] = nums[i];
        }

        for(int i=lastNonZeroFoundAt;i < n;i++) nums[i] = 0;
    }
};