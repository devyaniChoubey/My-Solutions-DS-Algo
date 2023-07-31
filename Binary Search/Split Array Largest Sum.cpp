https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    int countArrays(vector<int>& nums, int maxSum){
        int arrayCount = 1;
        int sum = 0;

        for(auto it:nums){
            if(sum+it > maxSum){
                arrayCount++;
                sum = it;
            }else{
                sum += it;
            }
        }
        return arrayCount;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = -1e9, high = 0;
        for(auto it:nums){
            high += it;
            low = max(low, it);
        }

        while(low <= high){
            int mid = (low+high)/2;

            if(countArrays(nums, mid) > k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};