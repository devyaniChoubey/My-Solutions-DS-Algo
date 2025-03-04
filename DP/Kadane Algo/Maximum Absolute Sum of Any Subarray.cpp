https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = -1e9;
        int posCurSum = 0, negCurSum = 0;

        for(auto &it:nums){
            posCurSum += it;
            negCurSum += it;
            if(posCurSum < 0) posCurSum = 0;
            maxSum = max(maxSum, posCurSum);
            if(negCurSum > 0) negCurSum = 0;
            maxSum = max(maxSum, abs(negCurSum));
        }

        return maxSum;
    }
};