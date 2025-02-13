https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;

        for(auto &it:nums){
            pq.push(it);
        }

        int operation = 0;

        while(true){
            if(pq.size() >= 2 && pq.top() < k){
                long long x = pq.top();
                pq.pop();
                long long y = pq.top();
                pq.pop();

                pq.push(2*x + y);
                operation++;
            }else break;
        }

        return operation;
    }
};