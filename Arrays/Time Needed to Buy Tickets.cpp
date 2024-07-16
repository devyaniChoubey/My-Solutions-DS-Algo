https://leetcode.com/problems/time-needed-to-buy-tickets/

//approach 1

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;

        int time = 0;

        for(int i=0;i < tickets.size();i++){
            q.push(i);
        }

        while(!q.empty()){
            int ind = q.front();

            q.pop();

            if(tickets[ind] == 0) continue;

            tickets[ind]--;
            time++;

            if(tickets[ind] == 0 && ind == k) return time;

            q.push(ind);
        }

        return -1;
    }
};



//approach 2

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int time = 0;

        while(true){
            for(int i=0;i < tickets.size();i++){
                tickets[i]--;
                if(tickets[i] >= 0)time++;
                if(tickets[k] == 0) return time;
            }
        }

        return -1;
    }
};


//approach 3
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int time = 0;

        for(int i=0;i < tickets.size();i++){
            if(i <= k)time += min(tickets[i] , tickets[k]);
            else time += min(tickets[i] , tickets[k]-1);
        }

        return time;
    }
};