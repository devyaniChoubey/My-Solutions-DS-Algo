https://leetcode.com/problems/binary-search/description/


//Iterative
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low+high)/2;

            if(target == nums[mid]) return mid;
            else if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;
    }
};




//Recursive
class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target){
        if(low > high) return -1;
         
        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]){
            return binarySearch(nums, mid+1, high, target);
        }else{
            return binarySearch(nums, low, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};