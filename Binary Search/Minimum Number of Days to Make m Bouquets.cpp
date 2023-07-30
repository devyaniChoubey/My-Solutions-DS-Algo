https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/


class Solution {
public:
    int countBouquets(vector<int>& bloomDay, int dayNo, int k){
        int cnt = 0;
        int noOfBouquets = 0;
        for(auto it:bloomDay){
            if(dayNo >= it) cnt++;
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        return noOfBouquets;
    }
    int minDays(vector<int>& bloomDay, long m, long k) {
        if(m*k > bloomDay.size()) return -1;
        int low = 1e9, high = -1e9;
        for(auto it:bloomDay){
            low = min(low, it);
            high = max(high, it);
        }
        
        int requiredDays = 1e9;
        while(low <= high){
            int mid = (low+high)/2;
            int noOfBouquets = countBouquets(bloomDay, mid, k);
            if(noOfBouquets >= m){
                high = mid-1;
                requiredDays = min(requiredDays, mid);
            }else{
                low = mid+1;
            }
        }

        return requiredDays;

    }
};