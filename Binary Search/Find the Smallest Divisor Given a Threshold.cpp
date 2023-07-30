https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = -1e9;
        for(auto it:nums){
            high = max(high, it);
        }

        int minDivisor = 1e9;
        while(low <= high){
            int mid = (low+high)/2;
            
            int sum = 0;
            for(auto it:nums){
                sum += ceil((double)(it)/(double)(mid));
            }
            if(sum > threshold) low = mid+1;
            else{
                high = mid-1;
                minDivisor = min(minDivisor, mid);
            }
        }
        return minDivisor;
    }
};