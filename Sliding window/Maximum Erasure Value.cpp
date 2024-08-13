https://leetcode.com/problems/maximum-erasure-value/


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n, 0);

        prefixSum[0] = nums[0];

        for(int i=1;i < n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        unordered_map<int,int>ind;

        int left = 0, right = 0, ans = 0, sum = 0;

        while(right < n){
            sum += nums[right];
            if(ind.find(nums[right]) != ind.end()){
                left = max(left, ind[nums[right]] + 1);
                sum = prefixSum[right] - prefixSum[left-1];
            }

            ind[nums[right]] = right;

            ans = max(ans, sum);

            right++;
        } 

        return ans;
    }
};