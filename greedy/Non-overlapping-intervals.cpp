https://leetcode.com/problems/non-overlapping-intervals/description/

https://leetcode.com/problems/non-overlapping-intervals/editorial/

// inding the minimum number of intervals to remove is equivalent to finding the maximum number of non-overlapping intervals. This is the famous interval scheduling problem.

// Let's start by considering the intervals according to their end times. Consider the two intervals with the earliest end times. Let's say the earlier end time is x and the later one is y. We have x < y.

// If we can only choose to keep one interval, should we choose the one ending at x or ending at y? To avoid overlap, We should always greedily choose the interval with an earlier end time x. The intuition behind this can be summarized as follows:

// We choose either x or y. Let's call our choice k.
// To avoid overlap, the next interval we choose must have a start time greater than or equal to k.
// We want to maximize the intervals we take (without overlap), so we want to maximize our choices for the next interval.
// Because the next interval must have a start time greater than or equal to k, a larger value of k can never give us more choices than a smaller value of k.
// As such, we should try to minimize k. Therefore, we should always greedily choose x, since x < y.

// Sort intervals according to the end times.
// Initialize an answer variable ans = 0 and an integer k to represent the most recent end time. k should be initialized to a small value like INT_MIN.
// Iterate over the intervals. For each interval:
// If the start time is greater than or equal to k, update k to the end time of the current interval.
// Otherwise, increment ans.
// Return ans

class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
       return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),compare);
        int n = intervals.size();
        int prevEndTime  = intervals[0][1];
        int ans = 1;
        for(int i=1;i< n;i++){
            if(intervals[i][0] >= prevEndTime ){
                prevEndTime  = intervals[i][1];
                ans++;
            }
        }

        return n - ans;
    }
};