https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    static bool compareBYSecondVal(vector<int>&a, vector<int>&b){
        return (a[1] < b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compareBYSecondVal);
        int res = 1;
        int lastS = points[0][1];

        for(int i=1;i < points.size();i++){
            if(points[i][0] > lastS){
                lastS = points[i][1];
                res++;
            }
        }

        return res;
    }
};