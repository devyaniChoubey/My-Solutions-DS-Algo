https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/editorial/

class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            long long maxSum = 0;
    
            long long curSum = 0;
    
            int left = 0, right = 0, n = nums.size();
            unordered_map<int,int>pos;
            vector<long long>prefix(n, 0);
            prefix[0] = nums[0];
    
            for(int i=1;i < n;i++){
                prefix[i] = prefix[i-1] + nums[i];
            }
    
            while(right < n){
                if(pos.find(nums[right]) != pos.end()){
                    left = max(left, pos[nums[right]]+1);
                }
    
                if(right - left + 1 == k){
                    long long prevSum = 0;
                    if(left == 0) prevSum = 0;
                    else prevSum = prefix[left-1];
                    maxSum = max(maxSum, (long long)prefix[right] - prevSum);
                    left++;
                }
    
                pos[nums[right]] = right;
    
                right++;
            }
    
            return maxSum;
        }
    };