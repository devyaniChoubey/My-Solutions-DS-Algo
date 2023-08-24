https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
       return (a[1] < b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end(), comp);

        int lastArrowLoc = points[0][1];
        int arrows = 1;

        for(int i=1;i < points.size();i++){
            if(points[i][0] > lastArrowLoc){
               lastArrowLoc = points[i][1];
               arrows++;
            }
        }

        return arrows;
    }
};