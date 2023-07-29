https://leetcode.com/problems/single-element-in-a-sorted-array/description/



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // arr = [1 , 1 , 2 , 2 , 3 , 3 , 4, 5 , 5 , 6 , 6];
        // ind = [0 , 1 , 2 , 3 , 4 , 5 , 6, 7 , 8 , 9 , 10];

        // if single element will come in second half then index of pairs will be (even, odd) in 1st half
        // if single element will come in first half then index of pairs will be (odd, even) in 2nd half

        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low+high)/2;

            if(mid != n-1 && nums[mid] == nums[mid+1]){
                if(mid%2 == 0 && (mid+1)%2 != 0){
                    low = mid+1;
                }else high = mid - 1;

            }else if(mid != 0 && nums[mid-1] == nums[mid]){
                if((mid-1)%2 == 0 && (mid)%2 != 0){
                    low = mid+1;
                }else high = mid - 1;
            }else{
                return nums[mid];
            }
        }

        return -1;
    }
};