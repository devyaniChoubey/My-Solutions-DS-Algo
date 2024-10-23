https://leetcode.com/problems/my-calendar-ii/?envType=daily-question&envId=2024-09-27

class MyCalendarTwo {
public:
    vector<pair<int,int>>overlapped;
    vector<pair<int,int>>intervals;

    pair<int,int>getOverlapped(int start1, int start2, int end1, int end2){
      return { max(start1, start2) , min(end1, end2) };
    }

    bool doesOverLap(int s1, int s2, int e1, int e2){
        return (s2 < e1 && s1 < e2);
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int n = overlapped.size();
        int m = intervals.size();
        for(int i=0;i < n;i++){
            if(doesOverLap(overlapped[i].first, start, overlapped[i].second, end)){
                return false;
            }
        }

        for(int i=0;i < m;i++){
            if(doesOverLap(intervals[i].first, start, intervals[i].second, end)){
                overlapped.push_back(getOverlapped(intervals[i].first, start, intervals[i].second, end));
            }
        }

        intervals.push_back({start, end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */