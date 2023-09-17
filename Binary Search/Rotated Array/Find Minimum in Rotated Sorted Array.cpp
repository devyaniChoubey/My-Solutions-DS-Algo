https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size() - 1, low = 0;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }else if(nums[mid] <= nums[high]){
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};


//optimised

class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size() - 1, low = 0;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;

            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
            }
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }else if(nums[mid] <= nums[high]){
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};