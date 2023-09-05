https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    int divisionSum(vector<int>& nums, int divisor){
        int divisionResult = 0;

        for(int i=0;i < nums.size();i++){
            divisionResult += ceil((double)nums[i]/(double)divisor);
        }

        return divisionResult;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        while(low <= high){
            int mid = (low+high)/2;

            if(divisionSum(nums, mid) <= threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};