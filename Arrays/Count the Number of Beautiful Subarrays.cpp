https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

count subarray  with given XOR 0

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int prefixXor = 0;

        unordered_map<int ,int>freq;

        int n = nums.size();

        long long res = 0;

        for(int i=0;i < n;i++){
            prefixXor = prefixXor^nums[i];

            if(prefixXor == 0) res++;

           res += freq[prefixXor^0];

           freq[prefixXor]++;
        }

        return res;
    }
};