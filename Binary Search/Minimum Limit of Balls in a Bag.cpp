https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = -1e9;
        for(int it:nums){
            high = max(high , it);
        }
        int penalty = 1e9;

        while(low <= high){
            int mid = (low+high)/2;
            int noOfOperations = 0;
            for(auto it:nums) noOfOperations += ((it - 1)/mid);
            
            if(noOfOperations > maxOperations){
                low = mid+1;
            }else{
                high = mid-1;
                penalty = min(mid, penalty);
            }

        }
        return penalty;
    }
};