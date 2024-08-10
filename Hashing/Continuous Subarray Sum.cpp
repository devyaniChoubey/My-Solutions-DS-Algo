https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>seen;
        int n = nums.size();

        int prefix = 0;

        seen[0] = -1;

        for(int i=0;i < n;i++){
            prefix = prefix+nums[i];

            int prefixMod = prefix%k;

            if(seen.find(prefixMod) != seen.end()){
                if(i - seen[prefixMod] > 1) return true;
            }else seen[prefixMod] = i;
        }

        return false;
    }
};