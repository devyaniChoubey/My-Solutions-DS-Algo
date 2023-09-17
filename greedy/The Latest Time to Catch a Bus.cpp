https://leetcode.com/problems/the-latest-time-to-catch-a-bus/description/

https://leetcode.com/problems/the-latest-time-to-catch-a-bus/solutions/2262636/two-pointers/

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin() , buses.end());
        sort(passengers.begin() , passengers.end());

        int i=0, j =0, start = 0;

        while(i < buses.size() - 1 && j < passengers.size()){
            if(passengers[j] <= buses[i] && j - start < capacity){
                j++;
            }else{
                i++;
                start = j;
            }
        }

        

        while(j < passengers.size() && passengers[j] <= buses.back() && capacity){
            j++;
            capacity--;
        }

        int latest = capacity ? buses.back() : passengers[j-1];


        for(j=j-1;j >= 0 && latest == passengers[j];j--){
            latest = passengers[j] - 1;
        }

        return latest;
    }
};