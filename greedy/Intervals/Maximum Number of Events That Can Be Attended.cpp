https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int max_day = 0;
        int n = events.size();
        sort(events.begin(), events.end());

        for(int i=0;i < n;i++) max_day = max(max_day, events[i][1]);
        priority_queue<int, vector<int>, greater<int>>pq;

        int i=0;
        int ans = 0;

        for(int day=1;day <= max_day;day++){
            while(!pq.empty() && pq.top() < day) pq.pop();

            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                ans++;
            }

            if(i == n && pq.empty()) break;
        }

        return ans;
        
    }
};