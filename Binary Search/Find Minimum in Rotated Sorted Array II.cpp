https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};