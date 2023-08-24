https://leetcode.com/problems/merge-intervals/description/

Approach 2: Sorting
Intuition

If we sort the intervals by their start value, then each set of intervals that can be merged will appear as a contiguous "run" in the sorted list.

Algorithm

First, we sort the list as described. Then, we insert the first interval into our merged list and continue considering each interval in turn as follows:
If the current interval begins after the previous interval ends, then they do not overlap and we can append the current interval to merged. Otherwise, 
they do overlap, and we merge them by updating the end of the previous interval if it is less than the end of the current interval.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1;i < n;i++){
            if(intervals[i][0] >= ans.back()[0] && intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] ,intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};