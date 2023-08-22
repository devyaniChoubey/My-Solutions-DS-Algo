
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/189039/detailed-intuition-behind-deque-solution/


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        vector<long>prefix(n , 0);
        prefix[0] = nums[0];

        for(int i=1;i < n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int right = 0;
        int res = INT_MAX;

        while(right < n){
            if(prefix[right] >= k) res = min(res, right + 1);

            while(!dq.empty() && prefix[right] <= prefix[dq.back()]) dq.pop_back();

            dq.push_back(right);
            
            while(!dq.empty() && prefix[right] - prefix[dq.front()] >= k){
                res = min(res, right - dq.front());
                dq.pop_front();
            }

            right++;
        }

        if(res != INT_MAX)return res;
        else return -1;
    }
};