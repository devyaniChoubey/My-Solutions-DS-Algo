https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/


class Solution {
public:
    int countOfBouquets(vector<int>& bloomDay, int k, int day){
        int bouquetsCount = 0;
        int cnt = 0;

        for(int i=0;i < bloomDay.size();i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                bouquetsCount += (cnt/k);
                cnt = 0;
            }
        }

        bouquetsCount += (cnt/k);
        return bouquetsCount;
    }

    int minDays(vector<int>& bloomDay, long m, long k) {
        if(m*k > bloomDay.size()) return -1; 
        int high = *max_element(bloomDay.begin() , bloomDay.end());
        int low = *min_element(bloomDay.begin() , bloomDay.end());

        while(low <= high){
            int mid = (low+high)/2;

            if(countOfBouquets(bloomDay, k,mid) >= m){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};