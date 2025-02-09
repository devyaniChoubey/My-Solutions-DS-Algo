
https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09

i < j
nums[i] - i != nums[j] - j


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;

        unordered_map<int,int>freq;

        int n = nums.size();

        for(int i=0;i < n;i++){
            ans += (i - freq[nums[i] - i]);
            freq[nums[i] - i]++;
        }

        return ans;
    }
};

