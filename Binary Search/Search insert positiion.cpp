https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lowerbound = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return lowerbound;
    }
};