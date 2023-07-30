https://leetcode.com/problems/koko-eating-bananas/description/

range of banana eating rate can be form 1 to maxVal of banana among all  pile
class Solution {
public:
    long long totalTimeTaken(vector<int>& piles, int hourly){
        long long sum = 0;
        for(auto it:piles){
            if(it% hourly == 0) sum += it/hourly;
            else sum += ((it/hourly) + 1); 
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = -1;
        for(auto it:piles){
            maxVal = max(it, maxVal);
        }

        int low = 1, high = maxVal;
        int eatingRate = 1e9;
        while(low <= high){
            int mid = (low+high)/2;
            if(totalTimeTaken(piles, mid) > h){
                low = mid+1;
            }else{
                high = mid-1;
                eatingRate = min(eatingRate, mid);
            }
        }

        return eatingRate;
    }
};