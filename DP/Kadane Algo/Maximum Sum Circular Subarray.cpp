https://leetcode.com/problems/maximum-sum-circular-subarray/
https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/178422/one-pass

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = 1e9, maxSum = -1e9;

        int curMinSum = 0, curMaxSum = 0, totalSum = 0;
        int negCnt = 0;

        for(int i=0;i < nums.size();i++){
            totalSum += nums[i];
            if(nums[i] < 0) negCnt++;

            curMaxSum += nums[i];
            maxSum = max(maxSum, curMaxSum);
            if(curMaxSum < 0) curMaxSum = 0;
            

            curMinSum += nums[i];
            minSum = min(minSum, curMinSum);
            if(curMinSum > 0) curMinSum = 0;
        }

        if(negCnt == nums.size())return maxSum;

        return max(totalSum - minSum, maxSum);
    }
};