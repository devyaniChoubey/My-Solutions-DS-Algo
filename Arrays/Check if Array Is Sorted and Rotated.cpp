

https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i=0;i < n;i++){
            if(nums[i] > nums[(i+1)%n]) {
                if(k == 0) k=1;
                else return false;
            }
        }
        return true;
    }
};