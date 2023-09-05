https://leetcode.com/problems/koko-eating-bananas/description/

range of banana eating rate can be form 1 to maxVal of banana among all  pile

class Solution {
public:
    long long hoursRequiredToEatBananas(vector<int>& piles, int eatingRate){
        long long noOfHrRequired = 0;

        for(int i=0;i < piles.size();i++){
            noOfHrRequired += ceil((double)piles[i] / (double)eatingRate);
        } 

        return noOfHrRequired;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int high = *max_element(piles.begin() , piles.end());
        int low = 1;


        while(low <= high){
            long long mid = (low+high)/2;

            if(hoursRequiredToEatBananas(piles, mid) <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};