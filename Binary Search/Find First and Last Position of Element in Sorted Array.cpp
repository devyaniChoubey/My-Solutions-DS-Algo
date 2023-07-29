https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                if(nums[mid] == target) first = mid;
                high = mid - 1;
            }else low = mid+1;
        }

        low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] <= target){
                if(nums[mid] == target) last = mid;
                low = mid+1;
            }else high = mid-1;
        }

        return {first, last};
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        

        if(first == n || nums[first] != target) return {-1, -1};

        return {first, last-1};
    }
};