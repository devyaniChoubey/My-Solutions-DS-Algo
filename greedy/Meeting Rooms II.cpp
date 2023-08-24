https://leetcode.com/problems/meeting-rooms-ii/description/


// Algorithm

// Sort the given meetings by their start time.
// Initialize a new min-heap and add the first meeting's ending time to the heap. We simply need to keep track of the ending times as that tells us when a meeting room will get free.
// For every meeting room check if the minimum element of the heap i.e. the room at the top of the heap is free or not.
// If the room is free, then we extract the topmost element and add it back with the ending time of the current meeting we are processing.
// If not, then we allocate a new room and add it to the heap.
// After processing all the meetings, the size of the heap will tell us the number of rooms allocated. This will be the minimum number of rooms needed to accommodate all the meetings.
// Let us now look at the implementation for this algorithm.

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;

        int n = intervals.size();

        for(int i=0;i < n; i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin() , start.end());
        sort(end.begin() , end.end());

        int start_ptr = 0;
        int end_ptr = 0;

        int noRooms = 0;

        while(start_ptr < n){
            if(end[end_ptr] <= start[start_ptr]){
                end_ptr++;   
            }else{
                noRooms++; 
            }

            start_ptr++;
        }

        return noRooms;
    }

};



// Algorithm

// Sort the given meetings by their start time.
// Initialize a new min-heap and add the first meeting's ending time to the heap. We simply need to keep track of the ending times as that tells us when a meeting room will get free.
// For every meeting room check if the minimum element of the heap i.e. the room at the top of the heap is free or not.
// If the room is free, then we extract the topmost element and add it back with the ending time of the current meeting we are processing.
// If not, then we allocate a new room and add it to the heap.
// After processing all the meetings, the size of the heap will tell us the number of rooms allocated. This will be the minimum number of rooms needed to accommodate all the meetings.
// Let us now look at the implementation for this algorithm.

//Using min heap

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue <int, vector<int>, greater<int> > pq;

        sort(intervals.begin() , intervals.end());


        pq.push(intervals[0][1]);

        int n = intervals.size();

        for(int i=1;i < n;i++){
            if(intervals[i][0] >= pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }

        return pq.size();
    }

};