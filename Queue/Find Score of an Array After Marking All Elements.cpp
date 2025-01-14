https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool>marked(n+1, false);

        auto cmp = [](pair<int,int>&a, pair<int,int>&b){
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>pq(cmp);


        for(int i=0;i < n;i++){
            pq.push({nums[i] , i});
        }

        long long score = 0;

        while(!pq.empty()){
            int ind = pq.top().second;
            int val = pq.top().first;
            pq.pop();

            if(!marked[ind]){
                score += val;
                if(ind-1 >= 0) marked[ind-1] = true;
                if(ind+1 < n) marked[ind+1] = true;
                marked[ind] = true;
            }
        }

        return score;

    }
};



class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool>marked(n+1, false);

        priority_queue<pair<int,int>, vector<pair<int,int>>,  greater<pair<int,int>>>pq;


        for(int i=0;i < n;i++){
            pq.push({nums[i] , i});
        }

        long long score = 0;

        while(!pq.empty()){
            int ind = pq.top().second;
            int val = pq.top().first;
            pq.pop();

            if(!marked[ind]){
                score += val;
                if(ind-1 >= 0) marked[ind-1] = true;
                if(ind+1 < n) marked[ind+1] = true;
                marked[ind] = true;
            }
        }

        return score;

    }
};