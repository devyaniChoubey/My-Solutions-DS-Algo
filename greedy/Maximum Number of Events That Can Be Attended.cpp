https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=list&envId=oqv95d22


// #1. Sort the events based on starting day of the event
// #2. Now once you have this sorted events, every day check what are the events that can start today
// #3. for all the events that can be started today, keep their ending time in heap.
// # - Wait why we only need ending times ?
// # i) from today onwards, we already know this event started in the past and all we need to know is when this event will finish
// # ii) Also, another key to this algorithm is being greedy, meaning I want to pick the event which is going to end the soonest.
// # - So how do we find the event which is going to end the soonest?
// # i) brute force way would be to look at all the event's ending time and find the minimum, this is probably ok for 1 day but as we can only attend 1 event a day,
// # we will end up repeating this for every day and that's why we can utilize heap(min heap to be precise) to solve the problem of finding the event with earliest ending time
// #4. There is one more house cleaning step, the event whose ending time is in the past, we no longer can attend those event
// #5. Last but very important step, Let's attend the event if any event to attend in the heap.



class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());
        
        //priority queue contains deadlines of all the events
        //that have already started but not ended
        priority_queue <int, vector<int>, greater<int> > pq;

        int i = 0;
        int ans = 0;
        int n = events.size();

        for(int d=1;d <= 100000;d++){

            //remove all the events which are already over
            while(!pq.empty() && pq.top() < d){
                pq.pop();
            }

            //insert deadlines of all events that start today
            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }


            //if there are any events we can attend today we 
            //attend the event with smallest endtime
            if(!pq.empty()){
                ans++;
                pq.pop();
            }

            //if all elements are processed then stop 
            if(i == n && pq.empty()){
                break;
            }
        }

        return ans;
    }
};