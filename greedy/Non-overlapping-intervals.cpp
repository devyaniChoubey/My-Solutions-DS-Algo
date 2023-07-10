https://leetcode.com/problems/non-overlapping-intervals/description/


Sort intervals according to the end times.
Initialize an answer variable ans = 0 and an integer k to represent the most recent end time. k should be initialized to a small value like INT_MIN.
Iterate over the intervals. For each interval:
If the start time is greater than or equal to k, update k to the end time of the current interval.
Otherwise, increment ans.
Return ans

class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
       return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),compare);
        int n = intervals.size();
        int lastS = intervals[0][1];
        int ans = 1;
        for(int i=1;i< n;i++){
            if(intervals[i][0] >= lastS){
                lastS = intervals[i][1];
                ans++;
            }
        }

        return n - ans;
    }
};