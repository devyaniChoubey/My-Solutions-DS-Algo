https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());
        int n = events.size();
        
        //insert deadline of events in min heap
        priority_queue<int, vector<int>, greater<int>>pq;

        int i=0;
        int ans = 0;

        for(int d=1;d <= 100000;d++){

            //remove the events which already ended before current day
            while(!pq.empty() && pq.top() < d) pq.pop();

        
            //insert deadline of events which are starting today into heap
            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }
            
            //remove one event for current day (event with earliest deadline will be on top)
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }

            if(i == n && pq.empty()) break;
        }

        return ans;
    }
};