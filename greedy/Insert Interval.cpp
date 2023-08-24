https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};

        int i = 0;

        vector<vector<int>>ans;

        while(i < n && intervals[i][1] < newInterval[0]){
           ans.push_back(intervals[i]);
           i++;
        }

        while(i < n && newInterval[0] <= intervals[i][1] && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        ans.push_back(newInterval);


        while(i < n && newInterval[1] < intervals[i][0]){
           ans.push_back(intervals[i]);
           i++;
        }

        return ans;
    }
};