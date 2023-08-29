https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0;

        int n = nums.size();

        unordered_map<int , int>mp;

        mp[0] = 1;

        int res = 0;

        for(int i=0;i < n;i++){

            prefixSum += nums[i];

            int remainder = prefixSum%k;

            if(remainder<0)remainder+=k;
            
            res += mp[remainder];
            
            mp[remainder]++;
           
        }

        return res;
    }
};