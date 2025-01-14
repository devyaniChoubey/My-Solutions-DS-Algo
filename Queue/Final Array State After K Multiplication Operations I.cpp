https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/?envType=daily-question&envId=2024-12-16

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i < nums.size();i++){
            pq.push({nums[i] , i});
        }

        while(k != 0){
            auto it = pq.top();
            pq.pop();

            pq.push({it.first*multiplier, it.second});
            k--;
        }

        while(!pq.empty()){
            int ind = pq.top().second;
            nums[ind] = pq.top().first;
            pq.pop();
        }

        return nums;
    }
};
