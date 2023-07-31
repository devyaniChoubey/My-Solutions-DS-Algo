https://leetcode.com/problems/minimum-time-to-complete-trips/description/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 1, high = 1e14;
        while(low <= high){
            long long int mid = (high+low)/2;
            long long int tripsPossible = 0;
            for(auto it:time)tripsPossible += (mid/it);

            if(tripsPossible < totalTrips) low = mid+1;
            else{
                high = mid-1;
            }
        }

        return low;
    }
};