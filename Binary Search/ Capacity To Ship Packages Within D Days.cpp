https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    int findDaysCount(vector<int>& weights, int shipWtcap){
        int daysCount = 1;
        int wt = 0;
        for(auto it:weights){
            wt += it;
            if(wt > shipWtcap){
                daysCount++;
                wt = it;
            }
        }
        return daysCount;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = -1e9, high = 0;
        for(auto it:weights){
            high += it;
            low = max(it, low);
        }

        while(low <= high){     
            int mid = (low+high)/2;
            int dayCount = findDaysCount(weights, mid);

            if(dayCount > days){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};