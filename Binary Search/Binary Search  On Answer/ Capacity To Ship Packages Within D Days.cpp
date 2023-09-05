https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    int daysRequired(vector<int>& weights, int weightCap){
        int daysCnt = 1;
        int curWt = 0;

        for(int i=0;i < weights.size();i++){
            if(curWt + weights[i] <= weightCap){
                curWt = curWt + weights[i];
            }else{
                daysCnt++;
                curWt = weights[i];
            }
        }

        return daysCnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int high = 0;
        high = accumulate(weights.begin() , weights.end(),high);

        while(low <= high){
            int mid = (low+high)/2;

            if(daysRequired(weights,mid) <= days){
                high = mid-1;
            }else low = mid+1;
        }

        return low;
    }
};