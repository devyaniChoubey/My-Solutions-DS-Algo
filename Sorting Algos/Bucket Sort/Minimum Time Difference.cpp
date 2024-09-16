https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin() , timePoints.end());

        int n = timePoints.size();
        vector<int>bucket(24*60, false);

        for(int i=0;i < timePoints.size();i++){
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));
             
            int minute = 60*h + m;
            if (bucket[minute]) return 0;
            bucket[minute] = true;
        }

        int prevInd = INT_MIN;
        int firstInd = INT_MIN;

        int ans = INT_MAX;

        for(int i=0;i < 24*60;i++){
            if(bucket[i]){
                if(prevInd != INT_MIN) ans = min(ans, i - prevInd);
                prevInd = i;
                if(firstInd == INT_MIN) firstInd = i;
            }
        }

        ans = min(ans, 24*60 - prevInd  + firstInd);

        return ans;
    }
};