https://leetcode.com/problems/minimize-maximum-of-array/description/

class Solution {
public:
    int isPossible(vector<int>& nums, int max) {
        long ex = 0;
        for (int i : nums) {
            if (i > max) {
                long c = (i - max);
                if (c > ex) return false;
                ex -= c;
            } else {
                ex += (max - i);
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low = nums[0], high = 1e9;
        int ans = 1e9;

        while(low <= high){
            int mid = (low+high)/2;
            if(isPossible(nums, mid)){
                high = mid-1;
                ans = min(ans, mid);
            }else{
                low = mid+1;
            }

        }

        return ans;
    }
};