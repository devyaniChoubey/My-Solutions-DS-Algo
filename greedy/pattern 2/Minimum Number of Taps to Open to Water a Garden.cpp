https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        n++;
        vector<int>maxReach(n, 0);

        for(int i=0;i < n;i++){
            int start = i - ranges[i];
            int end = i + ranges[i];

            start = max(0, start);
            end = min(n-1, end);

            maxReach[start] = end;
        }
        
        int furthest_reach = 0;
        int cur_reach = 0;
        int taps = 0;

        for(int i=0;i < n - 1;i++){
            furthest_reach = max(furthest_reach, maxReach[i]);

            if(i == cur_reach){
                taps++;
                cur_reach = furthest_reach;
            }
        }
        
        if(cur_reach < n - 1) return -1;
        return taps;
    }
};