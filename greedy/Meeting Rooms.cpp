https://leetcode.com/problems/meeting-rooms/description/?envType=list&envId=oqv95d22


class Solution {
public:
    bool static comp(vector<int>&a , vector<int>&b){
        return (a[1] < b[1]);
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end(), comp);
        
        int n = intervals.size();

        for(int i=1;i < n;i++){
            if(intervals[i][0] < intervals[i - 1][1]) return false;
        }

        return true;
    }
};